/*
** desasm.c for desasm in /home/guigui/CoreWar/master/corewar/desasm
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Sun Apr 12 16:52:27 2015 guigui
** Last update Sun Apr 12 21:45:10 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "op.h"
#include "my.h"
#include "desasm.h"

t_dsm	*print_header(int fd, t_dsm *out, int j)
{
  read(fd, &(out->hexcode), sizeof(int));
  nflip_endian(&(out->hexcode), sizeof(int));
  read(fd, out->name, PROG_NAME_LENGTH);
  read(fd, &(out->prog_size), sizeof(int));
  nflip_endian(&(out->prog_size), sizeof(int));
  read(fd, out->comment, COMMENT_LENGTH);
  my_printf("hexcode = %x\n", out->hexcode);
  my_printf("prog_size = %d\n", out->prog_size);
  my_printf(".name = \"%s\"\n", out->name);
  my_printf(".comment = \"%s\"\n", out->comment);
  if ((out->raw = malloc(out->prog_size)) == NULL)
    return (NULL);
  if ((j = read(fd, out->raw, out->prog_size)) < out->prog_size)
    {
      my_printf("less octets than expected in the header\n");
      out->prog_size = j;
    }
  if (j > 100000 || out->prog_size > 100000)
    {
      my_printf("file too big, it can't be larger than 100 KB\n");
      return (NULL);
    }
  close(fd);
  return (out);
}

t_dsm	*open_cor(char *str)
{
  t_dsm	*out;
  int	fd;

  if (str == NULL || (out = malloc(sizeof(t_dsm))) == NULL ||
      (fd = open(str, O_RDONLY)) < 0 ||
      (out->name = malloc(PROG_NAME_LENGTH + 4)) == NULL ||
      (out->comment = malloc(COMMENT_LENGTH + 4)) == NULL)
    {
      if (fd == 0)
	my_printf("error opening file\n");
      return (NULL);
    }
  return (print_header(fd, out, 0));
}

void	calc_cdt(int *a, int *s, int r, char *args)
{
  if (a == NULL || s == NULL || args == NULL)
    return;
  if (r == T_DIR)
    {
      *s += DIR_SIZE;
      my_memcpy(a, args + *s, T_DIR);
      my_printf(" %%%d", *a);
    }
  else if (r == T_REG)
    {
      *s += REG_SIZE;
      my_memcpy(a, args + *s, T_REG);
      my_printf(" r%d", *a);
    }
  else if (r == T_IND)
    {
      *s += IND_SIZE;
      my_memcpy(a, args + *s, T_IND);
      my_printf(" %d", *a);
    }
  else
    *s += 0;
}

int	calc_sizes(char c, char *args)
{
  int	i;
  int	m;
  int	s;
  int	r;
  int	t;
  int	a;

  if (args == NULL)
    return (0);
  i = -1;
  m = (3 << 6);
  s = 0;
  while (++i < 4)
    {
      t = m >> (i * 2);
      r = c & t;
      r >>= (6  - (i * 2));
      a = 0;
      calc_cdt(&a, &s, r, args);
    }
  my_printf("\n");
  return (s);
}

void	free_dsm(t_dsm *ptr)
{
  if (ptr != NULL)
    return;
  free(ptr->name);
  free(ptr->comment);
  free(ptr->raw);
  free(ptr);
}
