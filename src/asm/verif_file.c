/*
** verif_file.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:25:53 2015 Guillaume Pirou
** Last update Sun Apr 12 17:25:54 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include "file.h"
#include "my.h"

int	verif_file(char *path)
{
  int	fd;
  off_t	size;
  t_ram	ram;
  long	ram_av;
  int	i;

  if (path == NULL || (fd = open(path, O_RDONLY)) < 0 ||
      (size = lseek(fd, 0, SEEK_END)) <= 0)
    {
      my_printf("Error opening the file\n");
      return (0);
    }
  get_raminfo(&ram);
  ram_av = ram.memfree;
  i = 0;
  while (++i < ram.unit)
    ram_av = ram_av * 1000L;
  close(fd);
  if ((ram_av / 4) < size)
    {
      my_printf("Cancelling opening, the file is too big\n");
      return (0);
    }
  return (1);
}
