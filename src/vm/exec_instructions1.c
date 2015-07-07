/*
** exec_instructions1.c for exec_instrcution1 in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:15:45 2015 alexis
** Last update Sun Apr 12 21:15:45 2015 alexis
*/

#include <stdlib.h>
#include "vm.h"
#include "asm.h"
#include "my_printf.h"
#include "my.h"

void    exec_ld(t_chp *cur, t_vm *vm, t_param *par, int pc_save)
{
  (void)pc_save;
  (void)vm;
  my_printf("\n%s is executing LD (0x2)\n", cur->header.name);
  my_printf("Loading %d bytes from the position %d into the register r%d\n",
	    REG_SIZE, (pc_save + (par->val[0] % IDX_MOD)), par->val[1]);
  if (!valid_reg(par->val[1]))
    {
      my_printf("Invalid register. Too bad!\n");
      return ;
    }
  cur->reg[par->val[1]] = par->val[0];
}

void    exec_add(t_chp *cur, t_vm *vm, t_param *par, int pc_save)
{
  (void)vm;
  (void)pc_save;
  my_printf("\n%s is executing ADD (0x4)\n", cur->header.name);
  my_printf("Adding %d with %d, to be stored in r%d\n",
	    par->val[0], par->val[1], par->val[2]);
  if (!valid_reg(par->val[0]) ||
      !valid_reg(par->val[1]) ||
      !valid_reg(par->val[2]))
    {
      my_printf("At least one register is invalid. Too bad!\n");
      return ;
    }
  cur->reg[par->val[2]] = par->val[0] + par->val[1];
}

void    exec_sub(t_chp *cur, t_vm *vm, t_param *par, int pc_save)
{
  my_printf("\n%s is executing SUB (0x5)\n", cur->header.name);
  my_printf("Substracting %d by %d, to be stored in r%d\n",
	    par->val[0], par->val[1], par->val[2]);
  if (!valid_reg(par->val[0]) ||
      !valid_reg(par->val[1]) ||
      !valid_reg(par->val[2]))
    {
      my_printf("At least one register is invalid. Too bad!\n");
      return ;
    }
  (void)vm;
  (void)pc_save;
  cur->reg[par->val[2]] = par->val[0] - par->val[1];
}

void    exec_and(t_chp *cur, t_vm *vm, t_param *par, int pc_save)
{
  (void)vm;
  (void)pc_save;
  my_printf("\n%s is executing AND (0x6)\n", cur->header.name);
  my_printf("Operating AND on the first two parameters, to be stored in r%d\n",
	    par->val[2]);
  if (!valid_reg(par->val[2]))
    {
      my_printf("Invalid register. Too bad!\n");
      return ;
    }
  cur->reg[par->val[2]] = par->val[0] & par->val[1];
}

void    exec_or(t_chp *cur, t_vm *vm, t_param *par, int pc_save)
{
  (void)vm;
  (void)pc_save;
  my_printf("\n%s is executing OR (0x7)\n", cur->header.name);
  my_printf("Operating OR on the first two parameters, to be stored in r%d\n",
	    par->val[2]);
  if (!valid_reg(par->val[2]))
    {
      my_printf("Invalid register. Too bad!\n");
      return ;
    }
  cur->reg[par->val[2]] = par->val[0] | par->val[1];
}
