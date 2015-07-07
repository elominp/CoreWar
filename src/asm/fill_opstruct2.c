/*
** fill_opstruct2.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:24:50 2015 Guillaume Pirou
** Last update Sun Apr 12 17:24:50 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "hashtable.h"
#include "my_mem.h"
#include "my.h"
#include "asm.h"

int	is_hexachar(char c)
{
  if ((c < '0' || c > '9') && !((c >= 'a' && c <= 'f') ||
				(c >= 'A' && c <= 'F')))
    return (0);
  return (1);
}

int	is_validarg(char *arg)
{
  int	i;
  int	len;

  if (arg == NULL || (len = my_strlen(arg)) <= 0)
    return (0);
  else if (len == 1 && !((arg[0] != LABEL_CHAR && arg[0] != DIRECT_CHAR) ||
			arg[0] == COMMENT_CHAR) && (arg[0] < '0' ||
						    arg[0] > '9'))
    return (1);
  else
    {
      if (len <= 1)
	return (0);
      i = 0;
      while (arg[++i] != '0')
	{
	  if (!is_hexachar(arg[i]) && (arg[0] != 'r' || (arg[0] != '%' &&
							 arg[1] != ':')))
	    {
	      my_printf("error : %s\n", arg);
	      return (0);
	    }
	}
    }
  return (1);
}

int	get_nbargs(char **tab)
{
  int	i;

  if (tab == NULL)
    return (0);
  i = -1;
  while (tab[++i] != NULL);
  return (i);
}

int	calc_args_onesize(char ref, char *args)
{
  char	type;

  if (args[0] == DIRECT_CHAR)
    type = T_DIR;
  else if (args[0] == 'r')
    type = T_REG;
  else
    type = T_IND;
  if (!(ref & type))
    return (0);
  else if (type == T_DIR)
    return (DIR_SIZE);
  else if (type == T_REG)
    return (REG_SIZE);
  else
    return (IND_SIZE);
}

int	calc_args_allsize(t_opc *op, char **args)
{
  int	i;
  int	size;
  int	temp;

  if (op == NULL || args == NULL)
    return (0);
  i = -1;
  size = 0;
  while (++i < op->nb_args)
    {
      if ((temp = calc_args_onesize(op->type[i], args[i])) <= 0)
	return (0);
      size += temp;
    }
  return (size);
}
