/*
** my_opcl.c for corewar in /home/pirou_g/corewar/lib_src/file
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:22:40 2015 Guillaume Pirou
** Last update Sun Apr 12 22:38:07 2015 gwendal querat
*/

#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "file.h"
#include "my_mem.h"

int	my_fclose(t_fle *file)
{
  if (file == NULL)
    return (0);
  gbgc_free(NULL, file->name);
  if ((file->fmode & O_WRONLY) || (file->fmode & O_RDWR))
    my_flush(file);
  if (file->fd >= 0)
    {
      if (close(file->fd) < 0)
	{
	  gbgc_free(NULL, file);
	  return (0);
	}
    }
  gbgc_free(NULL, file);
  return (1);
}

int	is_dir(char *path)
{
  int	fd;

  if (path == NULL)
    return (0);
  if ((fd = open(path, O_RDONLY | O_DIRECTORY)) < 0)
    return (0);
  close(fd);
  my_putstr2("Error : input is a folder\n");
  return (1);
}

void	my_create_file(char *name)
{
  int	fd;
  int	flag;

  flag = O_CREAT | O_WRONLY, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
  if (name == NULL)
    return;
  if ((fd = open(name, O_RDONLY)) >= 0)
    {
      close(fd);
      return;
    }
  if ((fd = open(name, flag)) < 0)
    return;
  close(fd);
}

t_fle	*my_fopen(char *name, int mode)
{
  t_fle	*out;

  if (name == NULL || (out = gbgc_malloc(NULL, sizeof(t_fle))) == NULL ||
      is_dir(name))
    return (NULL);
  if ((mode & O_WRONLY) || (mode & O_RDWR))
    my_create_file(name);
  if ((((out->name = my_strdup(name)) == NULL) ||
       (out->fd = open(name, mode)) < 0))
    return (NULL);
  out->fmode = mode;
  out->csr = 0;
  out->buff[0] = 0;
  out->buff[BUFF_SZ] = 0;
  out->status = NEOF;
  out->state = FLUSHED;
  return (out);
}
