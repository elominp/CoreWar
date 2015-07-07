/*
** compile_rc_fill_opstruct.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:24:15 2015 Guillaume Pirou
** Last update Sun Apr 12 17:24:15 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "hashtable.h"
#include "my_mem.h"
#include "my.h"
#include "asm.h"

int     compile_raw_code(t_opc *op, char **args)
{
  int   i;

  if (op == NULL || args == NULL || (op->args = gbgc_malloc(NULL, 1)) == NULL)
    return (0);
  op->size = 1;
  i = -1;
  while (args[++i] != NULL)
    {
      if (my_strlen(args[i]) >= 2)
        {
          args[i][2] = '\0';
          op->args[i] = my_getnbr_base(args[i], "0123456789ABCDEF");
          op->size += 1;
          if ((op->args = gbgc_realloc(op->args, op->size - 1, op->size)) ==
              NULL)
            return (0);
        }
      else
        return (0);
    }
  op->size -= 1;
  return (1);
}

int     fill_opstruct(t_opc *op, char **args, t_htb *lbl, int pos)
{
  if (op == NULL || args == NULL)
    return (1);
  if (!my_strcmp(op->keyword, ".code"))
    return (compile_raw_code(op, args));
  else if (lbl == NULL)
    return (first_pass(op, args));
  else
    return (second_pass(op, args, lbl, pos));
}
