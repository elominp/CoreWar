/*
** get_opc4.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:03:35 2015 Guillaume Pirou
** Last update Sun Apr 12 17:03:36 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my_mem.h"
#include "my.h"

t_opc	*get_longloadopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[12].mnemonique);
  opc->nb_args = op_tab[12].nbr_args;
  opc->type[0] = (char)op_tab[12].type[0];
  opc->type[1] = (char)op_tab[12].type[1];
  opc->hexcode = op_tab[12].code;
  opc->nb_cycles = op_tab[12].nbr_cycles;
  opc->description = my_strdup(op_tab[12].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_longloadindexopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[13].mnemonique);
  opc->nb_args = op_tab[13].nbr_args;
  opc->type[0] = (char)op_tab[13].type[0];
  opc->type[1] = (char)op_tab[13].type[1];
  opc->type[2] = (char)op_tab[13].type[2];
  opc->hexcode = op_tab[13].code;
  opc->nb_cycles = op_tab[13].nbr_cycles;
  opc->description = my_strdup(op_tab[13].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_longforkopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[14].mnemonique);
  opc->nb_args = op_tab[14].nbr_args;
  opc->type[0] = (char)op_tab[14].type[0];
  opc->hexcode = op_tab[14].code;
  opc->nb_cycles = op_tab[14].nbr_cycles;
  opc->description = my_strdup(op_tab[14].comment);
  opc->is_paramoct = 0;
  return (opc);
}

t_opc	*get_affopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[15].mnemonique);
  opc->nb_args = op_tab[15].nbr_args;
  opc->type[0] = (char)op_tab[15].type[0];
  opc->hexcode = op_tab[15].code;
  opc->nb_cycles = op_tab[15].nbr_cycles;
  opc->description = my_strdup(op_tab[15].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_rawopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(".code");
  return (opc);
}
