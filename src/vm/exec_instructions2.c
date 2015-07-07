/*
** exec_instructions2.c for exec_instrcu2 in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:15:59 2015 alexis
** Last update Sun Apr 12 21:15:59 2015 alexis
*/

#include <stdlib.h>
#include "vm.h"
#include "asm.h"
#include "my_printf.h"
#include "my.h"

void	exec_xor(t_chp *cur, t_vm *vm, t_param *par, int pc_save)
{
  (void)vm;
  (void)pc_save;
  my_printf("\n%s is executing XOR (0x8)\n", cur->header.name);
  my_printf("Operating XOR on the first two parameters, to be stored in r%d\n",
            par->val[2]);
  if (!valid_reg(par->val[2]))
    {
      my_printf("Invalid register. Too bad!\n");
      return ;
    }
  cur->reg[par->val[2]] = par->val[0] ^ par->val[1];
}
