/*
** config_vm.c for conf_vm in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:15:26 2015 alexis
** Last update Sun Apr 12 21:15:26 2015 alexis
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

int     assign_prog_id_and_adress(t_argv *args)
{
  if (args->progs == NULL)
    return (SUCCESS);
  if ((assign_id(args->progs)) == ERROR)
    return (ERROR);
  if ((assign_adress(args->progs, args->nb_progs)) == ERROR)
    return (ERROR);
  return (SUCCESS);
}

int     not_enough_ram()
{
  t_ram ram;

  get_raminfo(&ram);
  if (MEM_SIZE > ram.memavailable)
    {
      my_putstr2("error : not enough memory available"
                 "for the virtual machine !\n");
      return (1);
    }
  return (0);
}

void    display_end_game(t_vm *vm, t_chp *champs)
{
  t_chp *win;

  if (vm->win_gid == -1 || ((win = get_winner(vm->win_gid, champs)) == NULL))
    my_printf("no champion executed live, too bad !\n");
  else
    {
      my_printf("GAME OVER !\n"
                "champion %s won !\n"
		"his pid is %d\n"
                "his gid is %d\n",
                win->header.name, win->pid, win->gid);
    }
}

t_chp   *get_winner(int win, t_chp *champs)
{
  t_chp *cur;

  cur = champs;
  while ((cur))
    {
      if (cur->gid == win)
	return (cur);
      cur = cur->next;
    }
  return (NULL);
}

int     fill_champs_registers(t_chp *champs, t_vm *vm)
{
  t_chp *cur;
  int   i;

  cur = champs;
  if (champs == NULL)
    return (SUCCESS);
  if (vm == NULL)
    return (ERROR);
  while ((cur))
    {
      cur->reg[0] = cur->gid;
      my_printf("current proc's gid %d\n", cur->reg[0]); i = 1;
      while (i < REG_NUMBER)
        {
          cur->reg[i] = 0;
          i++;
        }
      cur = cur->next;
    }
  return (SUCCESS);
}
