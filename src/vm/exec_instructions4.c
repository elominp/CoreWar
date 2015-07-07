/*
** exec_instructions4.c for exec_instrcution4 in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:16:21 2015 alexis
** Last update Sun Apr 12 22:03:36 2015 adrien schmouker
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

void    exec_live(t_chp *cur, t_vm *vm, t_param *par)
{
  int   gid;
  t_chp *tmp;

  my_printf("live parameter : %d\n", par->val[0]);
  gid = par->val[0];
  tmp = vm->champs;
  while ((tmp))
    {
      if (tmp->gid == gid)
        {
          vm->win_gid = gid;
          tmp->last_live = 0;
        }
      tmp = tmp->next;
    }
  ++vm->nb_live;
  my_printf("%s executing LIVE (0x1)\n", cur->header.name);
  my_printf("vm->nb_live, %d\n"
            "last live %d\n"
            "gid %x\n"
            "PAR %x\n",
            vm->nb_live,
            cur->last_live,
            gid,
            par->val[0]);
}

void    exec_zjmp(t_chp *cur, t_param *par, int pc_save)
{
  my_printf("\n%s is jumping !\n", cur->header.name);
  my_printf("pc pre jump %x\n"
            "param dec %d\n"
            "mod %d\n",
            cur->pc, par->val[0], IDX_MOD);
  cur->pc = pc_save + (par->val[0] % IDX_MOD);
  my_printf("pc post jump %d\n"
            "modded param %d\n\n",
            cur->pc, (par->val[0] % IDX_MOD));
}

void    exec_instruction_no_code(t_chp *cur, t_vm *vm,
				 t_param *par, int pc_save)
{
  if (cur->inst->hexcode == LIVE)
    exec_live(cur, vm, par);
  else if (cur->inst->hexcode == ZJMP)
    exec_zjmp(cur, par, pc_save);
}

void    exec_st(t_chp *cur, t_vm *vm,
                t_param *par, int pc_save)
{
  int   test;

  test = 0x1337;
  if (par->type[0] != T_REG || (!valid_reg(par->val[0])))
    return ;
  my_printf("\n\n %s executing %s\n", cur->header.name, cur->inst->keyword);
  my_printf("pc %d adresse %d\n", pc_save, par->val[1]);
  if (par->type[1] != T_REG)
    write_to_circ_mem(&test, vm->mem,
                      (pc_save + (par->val[1] % IDX_MOD)), 4);
  else if (par->type[1] == T_REG)
    {
      if (valid_reg(par->val[1]))
        {
          cur->reg[par->val[1]] = cur->reg[par->val[0]];
          my_printf("reg %d valeur %d charge dans reg %d valeur %d\n",
                    par->val[0], cur->reg[par->val[0]],
                    par->val[1], cur->reg[par->val[1]]);
        }
    }
  (void)vm;
  (void)pc_save;
  my_putstr2("st over!--------------------------------------------------\n\n");
}

void    exec_instruction_coded(t_chp *cur, t_vm *vm,
                               t_param *par, int pc_save)
{
  void  (*a[20])(t_chp*, t_vm*, t_param*, int);

  a[0x02] = exec_ld;
  a[0x03] = exec_st;
  a[0x04] = exec_add;
  a[0x05] = exec_sub;
  a[0x06] = exec_and;
  a[0x07] = exec_or;
  a[0x08] = exec_xor;
  a[0x0A] = exec_ldi;
  a[0x0B] = exec_sti;
  a[0x0D] = exec_lld;
  a[0x0E] = exec_lldi;
  a[0x10] = exec_aff;
  if (cur->inst && (cur->inst->hexcode < 1 || cur->inst->hexcode > 0x0f))
    return ;
  (a[(int)cur->inst->hexcode])(cur, vm, par, pc_save);
}
