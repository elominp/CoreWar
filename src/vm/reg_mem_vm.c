/*
** reg_mem_vm.c for reg_mem_vm in /home/alexis/rendu/B2/CPE/Corewar/branch_alexis/corewar/src/vm
**
** Made by alexis
** Login   <alexis@epitech.net>
**
** Started on  Sun Apr 12 21:14:05 2015 alexis
** Last update Sun Apr 12 21:14:05 2015 alexis
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

int     circ(int cpt)
{
  int   tmp;

  tmp = cpt % MEM_SIZE;

  if ((MEM_SIZE + cpt) == 0)
    return (0);
  if (cpt < 0)
    cpt %= (MEM_SIZE + tmp);
  else
    cpt %= MEM_SIZE;
  return (cpt);
}

void    write_to_circ_mem(void *src, void *mem, int pos, int size)
{
  int   i;
  char  *srcc;
  char  *memc;

  srcc = src;
  memc = mem;
  i = -1;
  while (++i < size)
    {
      my_printf("writing into vm at pos %d\n", circ(pos + i));
      memc[circ(pos + i)] = srcc[i];
    }
}

int     valid_reg(int reg)
{
  if (reg >= 0 && reg < REG_NUMBER)
    return (1);
  return (0);
}

void    my_memcpy_circ(char *mem, char *buf, int size, int *i)
{
  int   j;

  j = 0;
  while (j < size)
    buf[j++] = mem[circ((*i)++)];
}

void    my_memset(char *mem, char c, int size)
{
  int   i;

  i = 0;
  while (i < size)
    mem[i++] = c;
}
