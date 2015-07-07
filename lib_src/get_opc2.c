/*
** get_opc2.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:03:20 2015 Guillaume Pirou
** Last update Sun Apr 12 17:03:21 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my_mem.h"
#include "my.h"

t_opc	*get_substractionopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[4].mnemonique);
  opc->nb_args = op_tab[4].nbr_args;
  opc->type[0] = (char)op_tab[4].type[0];
  opc->type[1] = (char)op_tab[4].type[1];
  opc->type[2] = (char)op_tab[4].type[2];
  opc->hexcode = op_tab[4].code;
  opc->nb_cycles = op_tab[4].nbr_cycles;
  opc->description = my_strdup(op_tab[4].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_andopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[5].mnemonique);
  opc->nb_args = op_tab[5].nbr_args;
  opc->type[0] = (char)op_tab[5].type[0];
  opc->type[1] = (char)op_tab[5].type[1];
  opc->type[2] = (char)op_tab[5].type[2];
  opc->hexcode = op_tab[5].code;
  opc->nb_cycles = op_tab[5].nbr_cycles;
  opc->description = my_strdup(op_tab[5].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_oropcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[6].mnemonique);
  opc->nb_args = op_tab[6].nbr_args;
  opc->type[0] = (char)op_tab[6].type[0];
  opc->type[1] = (char)op_tab[6].type[1];
  opc->type[2] = (char)op_tab[6].type[2];
  opc->hexcode = op_tab[6].code;
  opc->nb_cycles = op_tab[6].nbr_cycles;
  opc->description = my_strdup(op_tab[6].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_xoropcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[7].mnemonique);
  opc->nb_args = op_tab[7].nbr_args;
  opc->type[0] = (char)op_tab[7].type[0];
  opc->type[1] = (char)op_tab[7].type[1];
  opc->type[2] = (char)op_tab[7].type[2];
  opc->hexcode = op_tab[7].code;
  opc->nb_cycles = op_tab[7].nbr_cycles;
  opc->description = my_strdup(op_tab[7].comment);
  opc->is_paramoct = 1;
  return (opc);
}
