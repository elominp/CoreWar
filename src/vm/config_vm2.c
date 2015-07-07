/*
** config_vm2.c for conf vm2 in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:13:30 2015 alexis
** Last update Sun Apr 12 21:13:30 2015 alexis
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

int     buf_to_int(char *buf, int size)
{
  int   nb;

  nb = 0;
  my_printf("buf_to_int size %d\n", size);
  if (size == 4)
    {
      nb |= (buf[0] << 24) & 0xFF000000;
      my_printf("buf_to_int int %x\n", nb);
      nb |= (buf[1] << 16) & 0x00FF0000;
      my_printf("buf_to_int int %x\n", nb);
      nb |= (buf[2] << 8) & 0x0000FF00;
      my_printf("buf_to_int int %x\n", nb);
      nb |= (buf[3]) & 0x000000FF;
      my_printf("buf_to_int int %x\n", nb);
    }
  else if (size == 2)
    {
      nb |= (buf[0] << 8) & 0x0000FF00;
      my_printf("buf_to_int int %x\n", nb);
      nb |= (buf[1]) & 0x000000FF;
      my_printf("buf_to_int int %x\n", nb);
    }
  my_printf("buf_to_int result at return : %x\n", nb);
  return (nb);
}

int     no_bytecode_inst(char hexcode)
{
  if ((hexcode == LIVE || hexcode == ZJMP) ||
      (hexcode == FORK || hexcode == LFORK))
    return (SUCCESS);
  return (ERROR);
}

int     clock_tick(t_vm *vm, t_chp *champs, t_opc **op)
{
  ++vm->cycle;
  ++vm->total_cycles;
  if ((update_champs(vm, champs, op)) == ERROR)
    return (ERROR);
  if (vm->cycle == vm->cycle_to_die)
    {
      vm->cycle = 0;
      vm->cycle_to_die -= CYCLE_DELTA;
    }
  return (SUCCESS);
}

int     vm_main_loop(t_vm *vm, t_chp *champs, int fd, t_opc **op)
{
  if (champs == NULL)
    return (SUCCESS);
  while ((42))
    {
      dump_cycle_to_file(vm->mem, fd);
      if (vm->total_cycles == vm->dump)
        return (dump_memory_stdout(vm->total_cycles, fd));
      if (vm->cycle_to_die <= 0 || one_gid_left(champs, vm))
        return (END_GAME);
      if ((clock_tick(vm, champs, op)) == ERROR)
        return (SUCCESS);
      my_printf("%d %d\n", vm->cycle, vm->cycle_to_die);
    }
  return (SUCCESS);
}

int     init_vm_struct(t_vm *vm, t_argv *args, t_chp *champs, t_opc **op)
{
  if (args == NULL)
    return (ERROR);
  vm->cycle = 0;
  vm->total_cycles = 0;
  vm->live_count = 0;
  vm->cycle_to_die = CYCLE_TO_DIE;
  vm->dump = args->dump;
  if ((vm->mem = gbgc_calloc(sizeof(char) * MEM_SIZE + 1)) == NULL)
    return (ERROR);
  load_champs_to_vm(vm, champs);
  load_first_instructions(vm, champs, op);
  vm->champs = champs;
  vm->nb_live = 0;
  vm->win_gid = -1;
  return (SUCCESS);
}
