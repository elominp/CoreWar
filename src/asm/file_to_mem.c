/*
** file_to_mem.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:24:22 2015 Guillaume Pirou
** Last update Sun Apr 12 17:24:22 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "my_mem.h"
#include "file.h"
#include "asm.h"

int	tablen(char **tab)
{
  int	i;

  i = 0;
  if (tab == NULL)
    return (0);
  while (tab[i])
    i++;
  return (i);
}

int	nullify_tab(char **tab, int size)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = 0;
  while (i < size)
    tab[i++] = NULL;
  return (1);
}

char	**file_to_tab(t_fle *file, int len)
{
  char	**data;
  int	i;

  i = 0;
  if ((data = gbgc_malloc(NULL, sizeof(char*) * (len + 1))) == NULL)
    return (NULL);
  while (i < len)
    {
      data[i] = get_next_line(file);
      i++;
    }
  get_next_line(NULL);
  data[len] = NULL;
  return (data);
}

int	file_len(char *path)
{
  t_fle	*file_data;
  int	len;
  char	*tmp;

  len = 0;
  if ((file_data = my_fopen(path, O_RDONLY)) == NULL)
    {
      my_printf("error opening source file %s\n", path ? path : "undefined");
      return (-1);
    }
  while ((tmp = gnl_querat_g(file_data->fd)))
    {
      ++len;
      gbgc_free(NULL, tmp);
    }
  my_fclose(file_data);
  return (len);
}

t_ftm	*file_to_mem(char *path)
{
  char	**file;
  t_fle	*file_data;
  t_ftm	*out;
  int	len;

  if ((len = file_len(path)) == -1 ||
      (out = gbgc_malloc(NULL, sizeof(t_ftm))) == NULL)
    return (NULL);
  if ((file_data = my_fopen(path, O_RDONLY)) == NULL)
    {
      my_printf("error opening source file %s\n", path ? path : "undefined");
      return (NULL);
    }
  if ((file = file_to_tab(file_data, len)) == NULL)
    return (NULL);
  out->file = file_data;
  out->data = file;
  return (out);
}
