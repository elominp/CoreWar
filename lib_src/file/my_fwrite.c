/*
** my_fwrite.c for corewar in /home/pirou_g/corewar/lib_src/file
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:23:02 2015 Guillaume Pirou
** Last update Sun Apr 12 17:23:03 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include "my.h"
#include "file.h"
#include "champion.h"

void	write_ins(t_ins *ins, t_fle *file)
{
  if (ins == NULL)
    return;
  my_fwrite(ins->raw, sizeof(char), ins->size, file);
}

void	my_flush(t_fle *file)
{
  int	i;

  if (file == NULL)
    return;
  if (file->state != FLUSHED)
    write(file->fd, file->buff, file->csr);
  file->csr = 0;
  i = -1;
  while (++i < BUFF_SZ)
    file->buff[i] = 0;
}

size_t		my_fwrite(const void *ptr, size_t size,
			  size_t count, t_fle *file)
{
  size_t       	i;
  size_t       	j;
  const char	*tab;

  if (ptr == NULL || file == NULL || (size * count) > FILE_SZ_MAX ||
      (!(file->fmode & O_WRONLY) && !(file->fmode & O_RDWR)))
    return (-1);
  i = 0;
  j = 0;
  tab = ptr;
  while (j < (count * size))
    {
      while (((i + file->csr) < BUFF_SZ) && j < (count * size))
	file->buff[i++ + file->csr] = tab[j++];
      file->csr += i;
      file->state = NOT_FLUSHED;
      if (file->csr >= BUFF_SZ)
	{
	  my_flush(file);
	  i = 0;
	}
    }
  return ((size_t)j);
}
