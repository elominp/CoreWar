/*
** assign_pid.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:36:14 2015 gwendal querat
** Last update Sun Apr 12 20:22:37 2015 adrien schmouker
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"
#include "op.h"

int		already_assigned_pid(t_prog *prog, int lowest, t_prog *cmp)
{
  t_prog	*cur;

  if ((cur = prog) == NULL)
    return (0);
  if (cmp == NULL)
    while ((cur))
      {
	if (cur->id == lowest)
	  return (1);
	cur = cur->next;
      }
  else
    {
      while ((cur))
	{
	  if (cmp->id == cur->id && cur != cmp)
	    return (1);
	  cur = cur->next;
	}
    }
  return (0);
}

int		assign_id(t_prog *prog)
{
  t_prog	*cur;
  int		i;
  int		lowest;

  cur = prog;
  lowest = 1;
  while (cur)
    {
      if (cur->id == -1)
	{
	  while ((already_assigned_pid(prog, lowest, NULL)))
	    lowest++;
	  cur->id = lowest;
	}
      else
	if (already_assigned_pid(prog, -1, cur))
	  {
	    my_putstr2("two or more \"-n\" defined pids are conflicting !\n");
	    return (ERROR);
	  }
      i++;
      cur = cur->next;
    }
  return (SUCCESS);
}
