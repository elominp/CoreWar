/*
** dump.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:36:21 2015 gwendal querat
** Last update Sun Apr 12 20:23:40 2015 adrien schmouker
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

int	dump_cycle_to_file(char *mem, int fd)
{
  if ((lseek(fd, 0, SEEK_END)) == -1)
    return (ERROR);
  if ((write(fd, mem, MEM_SIZE)) == -1)
    return (ERROR);
  return (SUCCESS);
}

int	dump_hex_char(unsigned char c)
{
  my_putnbr_base(((c & 0xf0) >> 4), "0123456789abcdef");
  my_putnbr_base(((c & 0x0f)     ), "0123456789abcdef");
  return (SUCCESS);
}

int		dump_memory_stdout(int cycle, int fd)
{
  unsigned char	mem[MEM_SIZE];
  int		i;

  if ((lseek(fd, (cycle * MEM_SIZE), SEEK_SET)) == -1)
    return (ERROR);
  if ((read(fd, mem, MEM_SIZE)) == -1)
    return (ERROR);
  i = 0;
  while (i < MEM_SIZE)
    {
      dump_hex_char(mem[i]);
      my_putstr((i % 2 == 1) ? " " : "");
      i++;
      if (i > 0 && i % 32 == 0)
	my_putchar('\n');
    }
  return (SUCCESS);
}
