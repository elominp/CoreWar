/*
** conf_instruction.c for conf_instruction in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:14:57 2015 alexis
** Last update Sun Apr 12 21:14:57 2015 alexis
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

int             prep_instruction(t_chp *cur, t_vm *vm)
{
  t_param       par;
  int           i;
  int           pc_save;

  if (cur->inst == NULL)
    return (SUCCESS);
  pc_save = cur->pc - 1;
  i = -1;
  if (no_bytecode_inst(cur->inst->hexcode))
    {
      par.val[0] = get_param(vm, cur, T_DIR);
      exec_instruction_no_code(cur, vm, &par, pc_save);
    }
  else
    {
      get_bytecode(vm->mem[circ(cur->pc++)], par.type);
      while (++i < cur->inst->nb_args)
        {
          par.val[i] = get_param(vm, cur, par.type[i]);
        }
      exec_instruction_coded(cur, vm, &par, pc_save);
    }
  return (SUCCESS);
}

int     update_live(t_chp *cur, int cycle_to_die)
{
  if (cur->last_live >= cycle_to_die && cur->living)
    {
      my_printf("%s died\n", cur->header.name);
      cur->living = DED;
      return (0);
    }
  else
    ++cur->last_live;
  return (1);
}

int     load_next_instruction(t_vm *vm, t_chp *cur, t_opc **op)
{
  int   code;

  code = vm->mem[circ(cur->pc++)];
  my_printf("next instruction [%x]\n", code);
  if (code >= 1 && code <= 16)
    {
      cur->inst = op[code - 1];
      my_printf("cur keyword [%s]\n", cur->inst->keyword);
      cur->ticks = cur->inst->nb_cycles;
    }
  else
    {
      cur->ticks = 1;
      cur->inst = NULL;
    }
  cur = cur->next;
  return (SUCCESS);
}

int     update_champs(t_vm *vm, t_chp *champs, t_opc **op)
{
  t_chp *cur;

  if (champs == NULL)
    return (ERROR);
  cur = champs;
  while ((cur))
    {
      if (update_live(cur, vm->cycle_to_die))
        {
          if (cur->ticks == 0 && cur->living != DED)
            {
              if (cur->inst)
                my_printf("%s executing instruction %s\n",
                          cur->header.name, cur->inst->keyword);
              if ((prep_instruction(cur, vm)) == ERROR)
                return (ERROR);
              load_next_instruction(vm, cur, op);
            }
          --cur->ticks;
        }
      cur = cur->next;
    }
  return (SUCCESS);
}

int     load_first_instructions(t_vm *vm, t_chp *champs, t_opc **op)
{
  t_chp *cur;
  int   code;

  cur = champs;
  while ((cur))
    {
      code = vm->mem[circ(cur->pc++)];

      my_printf("first instruction [%x]\n", code);
      if (code >= 1 && code <= 16)
        {
          cur->inst = op[code - 1];
          my_printf("cur keyword [%s]\n", cur->inst->keyword);
          cur->ticks = cur->inst->nb_cycles;
        }
      else
        {
          cur->ticks = 1;
          cur->inst = NULL;
        }
      cur = cur->next;
    }
  return (SUCCESS);
}
