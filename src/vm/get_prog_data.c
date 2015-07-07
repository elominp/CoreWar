/*
** get_prog_data.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:36:33 2015 gwendal querat
** Last update Sun Apr 12 20:24:41 2015 adrien schmouker
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

unsigned int	chars_to_int(char *buf)
{
  unsigned int	code;

  code = 0;
  code |= (buf[0] << 24) & 0xFF000000;
  code |= (buf[1] << 16) & 0x00FF0000;
  code |= (buf[2] << 8 ) & 0x0000FF00;
  code |= (buf[3]) & 0x000000FF;
  return (code);
}

int	get_magic_code(int *code, t_prog *prog)
{
  if (((*code) = chars_to_int(prog->bin)) !=
     COREWAR_EXEC_MAGIC)
   {
     my_printf("file \"%s\" is not a .cor !\n"
	       "wrong header detected, aborting.\n",
	       prog->path);
     return (ERROR);
   }
 return (SUCCESS);
}

int	get_prog_name(char **name, t_prog *prog)
{
  (*name) = my_strndup(prog->bin + MAGIC_SIZE, PROG_NAME_LENGTH);
  if ((*name) == NULL)
    return (ERROR);
  return (SUCCESS);
}

int	get_prog_comment(char **com, t_prog *prog)
{
  (*com) = my_strndup(prog->bin + MAGIC_SIZE + PROG_NAME_LENGTH + 4,
		      COMMENT_LENGTH);
  if ((*com) == NULL)
    return (ERROR);
  my_printf("comment :%s\n", (*com));
  return (SUCCESS);
}

int	get_prog_raw(char **raw, t_prog *prog, int size)
{
  (*raw) = my_strndup(prog->bin + HEADER_OFFSET, size);
  if ((*raw) == NULL)
    return (ERROR);
  return (SUCCESS);
}
