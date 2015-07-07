/*
** gnl_querat_g.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:38:07 2015 Guillaume Pirou
** Last update Sun Apr 12 22:37:09 2015 guigui
*/

#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <unistd.h>
#include "my.h"
#include "my_mem.h"

int	gnl_len(int *iter)
{
  int	iter2;

  iter2 = (*iter);
  (*iter)++;

  return (iter2 * BUFF);
}

char		*mallocat(char *line, char *buffer, int *j, int lus)
{
  int		i;
  char		*dest;
  static int	iter = 1;

  i = 0;
  if (!(dest = gbgc_malloc(NULL, sizeof(char) * (gnl_len(&iter) + BUFF + 1))))
    return (NULL);
  if (line)
    while (line[i])
      {
	dest[i] = line[i];
	i++;
      }
  while ((*j) < lus && buffer[*j] != '\n')
    {
      dest[i] = buffer[(*j)];
      (*j)++;
      i++;
    }
  dest[i] = 0;
  gbgc_free(NULL, line);
  if (buffer[(*j)] == '\n')
    iter = 1;
  return (dest);
}

int	read_gnl(int *j, int *lus, const int *fd, char *buffer)
{
  if ((*j) >= (*lus))
    {
      (*j) = 0;
      if (((*lus) = read((*fd), buffer, BUFF)) <= 0)
	return (0);
    }
  return (1);
}

char	*gnl_querat_g(const int fd)
{
  static char	buffer[BUFF];
  static int	j;
  static int	lus;
  char		*line;

  line = NULL;
  if (BUFF < 1)
    return (NULL);
  while (42)
    {
      if (fd < 0)
	return (NULL);
      if (!(read_gnl(&j, &lus, &fd, buffer)))
	return (line);
      if (!(line = mallocat(line, buffer, &j, lus)))
	return (NULL);
      if (buffer[j] == '\n')
	{
	  j++;
	  return (line);
	}
    }
  return (line);
}
