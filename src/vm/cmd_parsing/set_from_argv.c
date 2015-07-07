/*
** set_from_argv.c for  in /home/querat_g/corewar/src/vm/cmd_parsing
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:35:15 2015 gwendal querat
** Last update Sun Apr 12 17:35:16 2015 gwendal querat
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"
#include "op.h"

int	set_prog_adress(char **argv, int *i, int *a)
{
  ++(*i);
  if (argv[(*i)] == NULL)
    {
      my_putstr2("no argument after \"-a\"\n");
      return (ERROR);
    }
  if (!isnum(argv[(*i)]))
    {
      my_putstr2("argument after \"-a\" must be an unsigned number !\n");
      return (ERROR);
    }
  (*a) = (my_atoi(argv[(*i)]) % MEM_SIZE);
  ++(*i);
  return (SUCCESS);
}

int	set_prog_id(char **argv, int *i, int *prog_id)
{
  ++(*i);
  if (argv[(*i)] == NULL)
    {
      my_putstr2("no argument after \"-n\"\n");
      return (ERROR);
    }
  if (!isnum(argv[(*i)]))
    {
      my_putstr2("argument after \"-n\" must be an unsigned number !\n");
      return (ERROR);
    }
  (*prog_id) = my_atoi(argv[(*i)]);
  ++(*i);
  return (SUCCESS);
}

int	set_dump(char **argv, int *i, int *dump)
{
  ++(*i);
  if (argv[(*i)] == NULL)
    {
      my_putstr2("no argument after \"-dump\"\n");
      return (ERROR);
    }
  if (!isnum(argv[(*i)]))
    {
      my_putstr2("argument after \"-dump\" must be an unsigned number !\n");
      return (ERROR);
    }
  (*dump) = my_atoi(argv[(*i)]);
  ++(*i);
  return (SUCCESS);
}

int	set_prog_path(char **argv, int *i, char **adress)
{
  if (argv[(*i)] == NULL)
    {
      my_putstr2("no path specified after -a / -n\n");
      return (ERROR);
    }
  (*adress) = my_strdup(argv[(*i)]);
  ++(*i);
  return (SUCCESS);
}
