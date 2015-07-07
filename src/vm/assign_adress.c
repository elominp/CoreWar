/*
** assign_adress.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:35:58 2015 gwendal querat
** Last update Sun Apr 12 20:21:22 2015 adrien schmouker
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"
#include "op.h"

int		already_assigned_adress(t_prog *prog, t_prog *cmp)
{
  t_prog	*cur;

  if ((cur = prog) == NULL)
    return (0);
  while ((cur))
    {
      if (cmp->adress == cur->adress && cur != cmp)
	{
	  my_putstr2("two or more \"-a\" defined adresses"
		     " are conflicting !\n");
	  return (1);
	}
      cur = cur->next;
    }
  return (0);
}

int	assign_default_adress(t_prog *cur, int nb_progs, int *i)
{
  int	offset;

  offset = (MEM_SIZE / nb_progs);
  cur->adress = offset * (*i);
  if (cur->adress == MEM_SIZE)
    --cur->adress;
  return (SUCCESS);
}

int		assign_adress(t_prog *prog, int nb_progs)
{
  t_prog	*cur;
  int		i;

  cur = prog;
  i = 0;
  while (cur)
    {
      if (cur->adress != UNDEFINED)
	{
	  if (already_assigned_adress(prog, cur))
	    return (ERROR);
	}
      else
	assign_default_adress(cur, nb_progs, &i);
      i++;
      cur = cur->next;
    }
  return (SUCCESS);
}
