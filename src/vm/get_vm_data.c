/*
** get_vm_data.c for get_vmèdata in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:15:10 2015 alexis
** Last update Sun Apr 12 22:42:26 2015 adrien schmouker
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

int     get_param_size(char code)
{
  int   sz;

  my_printf("%d\n", code);
  sz = 0;
  if (code == T_IND)
    sz = IND_SIZE;
  else if (code == T_DIR)
    sz = DIR_SIZE;
  else if (code == T_REG)
    sz = REG_SIZE;
  else
    my_printf("unknown parameter type\n");
  return (sz);
}

int     get_param(t_vm *vm, t_chp *cur, char code)
{
  char  parbuf[DIR_SIZE | REG_SIZE | IND_SIZE];
  int   sz;
  int   res;

  sz = 0;
  if (!code)
    return (0);
  sz = get_param_size(code);
  my_memcpy_circ(vm->mem, parbuf, sz, &cur->pc);
  res = buf_to_int(parbuf, sz);
  my_putchar('\n');
  my_putnbr_base(code, "01");
  my_putchar('\n');
  if (code == T_REG)
    {
      --res;
      my_printf("get param reg : %d\n", res);
    }
  my_printf("get param dir/indir : %x\n", res);
  return (res);
}

void    get_bytecode(char bytecode, char *type)
{
  type[0] = 0 | ((bytecode & 0b11000000) >> 6);
  type[1] = 0 | ((bytecode & 0b00110000) >> 4);
  type[2] = 0 | ((bytecode & 0b00001100) >> 2);
  type[3] = 0 | ((bytecode & 0b00000011));
}

int     init_vm(t_argv *args)
{
  t_chp *champ;
  t_vm  vm;
  t_opc **op;
  int   fd;

  if (((op = get_opcodetab()) == NULL)                                       ||
      ((load_files(args)) == ERROR)                                          ||
      ((champ = init_champ_structs(args, args->progs)) == NULL)              ||
      ((champ_to_linked_list(champ, args->nb_progs)) == ERROR)               ||
      ((init_vm_struct(&vm, args, champ, op)) == ERROR)                      ||
      ((fd = open(DUMP_FILE, O_RDWR | O_CREAT | O_TRUNC, S_IRWXU)) == -1)    ||
      ((fill_champs_registers(champ, &vm)) == ERROR)                         ||
      ((vm_main_loop(&vm, champ, fd, op)) == ERROR)                          ||
      ((close(fd)) == -1))
    return (ERROR);
  display_end_game(&vm, champ);
  return (SUCCESS);
}
