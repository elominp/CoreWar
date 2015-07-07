/*
** exec_instructions3.c for exec_nstruction3 in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:16:10 2015 alexis
** Last update Sun Apr 12 21:16:10 2015 alexis
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

void    exec_sti(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save)
{
  cur = cur;
  vm = vm;
  par = par;
  pc_save = pc_save;
  my_printf("sti !\n");
}

void    exec_lld(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save)
{
  cur = cur;
  vm = vm;
  par = par;
  pc_save = pc_save;
  my_printf("lld !\n");
}

void    exec_lldi(t_chp *cur, t_vm *vm,
		  t_param *par, int pc_save)
{
  cur = cur;
  vm = vm;
  par = par;
  pc_save = pc_save;
  my_printf("lldi !\n");
}

void    exec_aff(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save)
{
  cur = cur;
  vm = vm;
  par = par;
  pc_save = pc_save;
  my_printf("aff !\n");
}
