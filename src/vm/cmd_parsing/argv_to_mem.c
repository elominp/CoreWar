/*
** argv_to_mem.c for  in /home/querat_g/corewar/src/vm/cmd_parsing
**
** Made by gwendal querat
** Login   <querat_g@epitech.net>
**
** Started on  Sun Apr 12 17:34:50 2015 gwendal querat
** Last update Sun Apr 12 20:32:45 2015 adrien schmouker
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"

int	isnum(char *str)
{
  if (str == NULL || !my_strlen(str))
    return (0);
  while ((*str))
    {
      if ((*str) < '0' || (*str) > '9')
	return (0);
      str++;
    }
  return (1);
}

int	get_argv_data(char **argv, t_argv *args, t_prog *cur, int *i)
{
  if (!my_strcmp(argv[(*i)], "-dump"))
    {
      if (!set_dump(argv, i, &args->dump))
	return (ERROR);
    }
  else if (!my_strcmp(argv[(*i)], "-n"))
    {
      if (!set_prog_id(argv, i, &cur->id))
	return (ERROR);
    }
  else if (!my_strcmp(argv[(*i)], "-a"))
    {
      if (!set_prog_adress(argv, i, &cur->adress))
	return (ERROR);
    }
  else
    {
      if (!set_prog_path(argv, i, &cur->path))
	return (ERROR);
    }
  return (SUCCESS);
}

int		check_argv(char **argv, t_argv *args)
{
  int		i;
  t_prog	*cur;

  i = 1;
  cur = NULL;
  if (argv[1] == NULL)
    return (SUCCESS);
  while (argv[i])
    {
      if ((cur == NULL || has_path(cur)) && my_strcmp(argv[i], "-dump"))
	{
	  if ((args->progs = add_elem_to_t_prog(args->progs)) == NULL)
	    return (ERROR);
	  cur = last_elem(args->progs);
	  clear_prog_struct(cur);
	  ++args->nb_progs;
	}
      if (!get_argv_data(argv, args, cur, &i))
	return (ERROR);
    }
  if (argv[i] == NULL && cur && cur->path == NULL)
    return (my_putstr("no program path specified after -n/-a\n") & ERROR);
  return (SUCCESS);
}
