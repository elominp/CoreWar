/*
** load_files.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:36:06 2015 gwendal querat
** Last update Sun Apr 12 22:23:22 2015 guigui
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"
#include "asm.h"
#include "op.h"

int	open_champ_file(char *path)
{
  int	file;

  file = ERROR;
  if (path == NULL || !path)
    return (ERROR);
  if ((file = open(path, O_RDONLY)) == -1)
    {
      my_printf("could not open file <%s> !\n"
		"make sure the file exists "
		"and that you have the correct access "
		"rights !\n",
		path);
      return (ERROR);
    }
  return (file);
}

int	load_champ_to_memory(t_prog *cur)
{
  int	fd;
  int	file_size;

  if ((fd = open_champ_file(cur->path)) == ERROR)
    return (ERROR);
  if ((file_size = lseek(fd, 0, SEEK_END)) <
      PROG_NAME_LENGTH + COMMENT_LENGTH + 4 + 17)
    return (my_printf("file is too small to contain a header !\n") & ERROR);
  if (file_size > 1000000)
    return (my_printf("file is too big !\n") & ERROR);
  lseek(fd, 0, SEEK_SET);
  if ((cur->bin = gbgc_calloc(sizeof(char) * (file_size + 1))) == NULL)
    {
      my_printf("malloc failed !\n");
      return (ERROR);
    }
  read(fd, cur->bin, file_size);
  close(fd);
  cur->size = file_size;
  return (SUCCESS);
}

int		load_files(t_argv *args)
{
  t_prog	*cur;

  if ((cur = args->progs) == NULL)
    return (SUCCESS);
  while ((cur))
    {
      if ((load_champ_to_memory(cur)) == ERROR)
	return (ERROR);
      cur = cur->next;
    }
  return (SUCCESS);
}
