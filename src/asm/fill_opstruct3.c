/*
** fill_opstruct3.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:24:56 2015 Guillaume Pirou
** Last update Sun Apr 12 17:24:57 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "hashtable.h"
#include "my_mem.h"
#include "my.h"
#include "asm.h"

int	is_prmlabel(char *str)
{
  return (my_strlen(str) > 2 && str[0] == '%' && str[1] == ':');
}

int	set_param(t_prm *dta)
{
  t_lng	data;
  int	*lab;

  if (dta == NULL || dta->dest == NULL || dta->size <= 0 || dta->arg == NULL ||
      dta->lbl == NULL)
    return (0);
  if (is_prmlabel(dta->arg))
    {
      if ((lab = hasht_getel(dta->arg + 2,
			     my_strlen(dta->arg + 2), dta->lbl)) == NULL)
	return (0);
      data.data = (*lab - dta->pos);
    }
  else if (dta->arg[0] == 'r' || dta->arg[0] == '%')
    data.data = asm_getnbr(dta->arg + 1);
  else
    data.data = asm_getnbr(dta->arg);
  my_memcpy(dta->dest, data.tab, dta->size);
  return (1);
}

int	calc_arg_offset(int arg, int *sizes)
{
  int	i;
  int	off;

  if (arg <= 0 || sizes == NULL)
    return (0);
  i = -1;
  off = 0;
  while (++i < arg)
    off += sizes[i];
  return (off);
}

void		show_tab(void *ptr, size_t size)
{
  size_t	i;
  char		*tab;
  int		t;

  if (ptr == NULL || !size)
    return;
  i = 0;
  tab = (char *)ptr;
  while (i < size)
    {
      t = tab[i++] % 127;
      my_printf("%d ", t);
    }
  my_putchar('\n');
}

int	first_pass(t_opc *op, char **args)
{
  int	nb;
  int	i;
  char	*comp[MAX_ARGS_NUMBER];

  i = -1;
  if (op == NULL || args == NULL || (nb = get_nbargs(args)) != op->nb_args ||
      (op->size = calc_args_allsize(op, args)) <= 0 ||
      (op->args = gbgc_calloc(op->size)) == NULL)
    return (0);
  op->size += 1 + ((op->is_paramoct) ? 1 : 0);
  i = -1;
  while (++i < nb && args[i] != NULL)
    {
      if ((op->size_args[i] = calc_args_onesize(op->type[i], args[i])) <= 0 ||
	  (comp[i] = gbgc_calloc(op->size_args[i])) == NULL)
	return (0);
    }
  return (1);
}
