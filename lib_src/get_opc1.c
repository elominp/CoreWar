/*
** get_opc1.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:03:13 2015 Guillaume Pirou
** Last update Sun Apr 12 17:03:14 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my_mem.h"
#include "my.h"

t_opc	*get_liveopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[0].mnemonique);
  opc->nb_args = op_tab[0].nbr_args;
  opc->type[0] = (char)op_tab[0].type[0];
  opc->hexcode = op_tab[0].code;
  opc->nb_cycles = op_tab[0].nbr_cycles;
  opc->description = my_strdup(op_tab[0].comment);
  opc->is_paramoct = 0;
  return (opc);
}

t_opc	*get_loadopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[1].mnemonique);
  opc->nb_args = op_tab[1].nbr_args;
  opc->type[0] = (char)op_tab[1].type[0];
  opc->type[1] = (char)op_tab[1].type[1];
  opc->hexcode = op_tab[1].code;
  opc->nb_cycles = op_tab[1].nbr_cycles;
  opc->description = my_strdup(op_tab[1].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_storeopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[2].mnemonique);
  opc->nb_args = op_tab[2].nbr_args;
  opc->type[0] = (char)op_tab[2].type[0];
  opc->type[1] = (char)op_tab[2].type[1];
  opc->hexcode = op_tab[2].code;
  opc->nb_cycles = op_tab[2].nbr_cycles;
  opc->description = my_strdup(op_tab[2].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_additionopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[3].mnemonique);
  opc->nb_args = op_tab[3].nbr_args;
  opc->type[0] = (char)op_tab[3].type[0];
  opc->type[1] = (char)op_tab[3].type[1];
  opc->type[2] = (char)op_tab[3].type[2];
  opc->hexcode = op_tab[3].code;
  opc->nb_cycles = op_tab[3].nbr_cycles;
  opc->description = my_strdup(op_tab[3].comment);
  opc->is_paramoct = 1;
  return (opc);
}
