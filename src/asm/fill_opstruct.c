/*
** fill_opstruct.c for asm in /home/pirou_g/corewar/src/asm
**
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
**
** Started on  Sun Apr 12 17:24:46 2015 Guillaume Pirou
** Last update Sun Apr 12 17:58:00 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "hashtable.h"
#include "my_mem.h"
#include "my.h"
#include "asm.h"

char	calc_param_oct(char **args)
{
  int	i;
  char	oct;

  if (args == NULL)
    return (0);
  i = -1;
  oct = 0;
  while (args[++i] != NULL && i < 4)
    {
      if (args[i][0] == '%')
	oct |= (T_DIR << (6 - (i * 2)));
      else if (args[i][0] == 'r')
	oct |= (T_REG << (6 - (i * 2)));
      else
	oct |= (T_IND << (6 - (i * 2)));
    }
  return (oct);
}

void	add_three_args_prm(t_prm *prm, int size, int pos, char *arg)
{
  if (prm == NULL || arg == NULL)
    return;
  prm->size = size;
  prm->pos = pos;
  prm->arg = arg;
}

void	add_rest_args_prm(t_prm *prm, char *dest, t_htb *lbl)
{
  if (prm == NULL || dest == NULL || lbl == NULL)
    return;
  prm->dest = dest;
  prm->lbl = lbl;
}

void	cpy_prm(t_opc *op, char **comp, int i)
{
  if (op == NULL || comp == NULL)
    return;
  my_memcpy(op->args + calc_arg_offset(i, op->size_args), comp[i],
	    op->size_args[i]);
}

int	second_pass(t_opc *op, char **args, t_htb *lbl, int pos)
{
  int	nb;
  int	i;
  char	*comp[MAX_ARGS_NUMBER];
  t_prm	prm;

  if (op == NULL || args == NULL || (nb = get_nbargs(args)) != op->nb_args ||
      lbl == NULL || (op->size = calc_args_allsize(op, args)) <= 0 ||
      (op->args = gbgc_calloc(op->size + 1)) == NULL)
    return (0);
  op->size += 1 + ((op->is_paramoct) ? 1 : 0);
  i = -1;
  while (++i < nb && args[i] != NULL)
    {
      if ((op->size_args[i] = calc_args_onesize(op->type[i], args[i])) <= 0 ||
	  (comp[i] = gbgc_calloc(op->size_args[i])) == NULL)
	return (0);
      op->param_oct = calc_param_oct(args);
      add_three_args_prm(&prm, op->size_args[i], pos, args[i]);
      add_rest_args_prm(&prm, comp[i], lbl);
      if (!set_param(&prm))
	return (0);
      nflip_endian(comp[i], op->size_args[i]);
      cpy_prm(op, comp, i);
    }
  return (1);
}
