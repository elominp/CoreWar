/*
** load_champs.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:37:41 2015 gwendal querat
** Last update Sun Apr 12 20:29:22 2015 adrien schmouker
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

int	write_champ(t_chp *champ, char *mem)
{
  int	warning;
  int	j;

  warning = 0;
  j = 0;
  while (j < champ->header.prog_size)
    {
      if (!warning && mem[circ((champ->pc + j))] != 0)
	{
	  my_putstr2("warning : one of the programs is overwriting another. "
		     "If this is an issue, make sure to set a proper adress "
		     "or to load less or smaller programs !\n");
	  ++warning;
	}
      mem[circ((champ->pc + j))] = champ->raw[j];
      j++;
    }
  return (SUCCESS);
}

int	load_champs_to_vm(t_vm *vm, t_chp *champs)
{
  t_chp	*cur;

  if ((cur = champs) == NULL)
    return (ERROR);
  while ((cur))
    {
      write_champ(cur, vm->mem);
      cur = cur->next;
    }
  return (SUCCESS);
}
