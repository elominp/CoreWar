/*
** main.c for  in /home/querat_g/corewar/src/vm
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 12 18:16:47 2015 gwendal querat
** Last update Sun Apr 12 20:17:06 2015 gwendal querat
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

int	one_gid_left(t_chp *champs, t_vm *vm)
{
  t_chp	*cur;
  int   gid;
  int	first;

  (void)vm;
  gid = -1;
  first = 1;
  if ((cur = champs) == NULL)
    return (1);
  while ((cur))
    {
      if (cur->living != DED && first)
	{
	  first = 0;
	  gid = cur->gid;
	}
      if (cur->living != DED && !first && cur->gid != gid)
	return (0);
      cur = cur->next;
    }
  return (gid);
}

int		main(int ac, char **argv)
{
  t_argv	args;

  (void)ac;
  gbgc_init();
  clear_args_struct(&args);
  if (((check_argv(argv, &args)) == ERROR)		||
      ((assign_prog_id_and_adress(&args)) == ERROR)	||
      ((init_vm(&args)) == ERROR))
    {
      gbgc_erase(NULL);
      return (EXIT_FAILURE);
    }
  gbgc_erase(NULL);
  return (EXIT_SUCCESS);
}
