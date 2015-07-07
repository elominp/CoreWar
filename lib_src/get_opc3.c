/*
** get_opc3.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:03:26 2015 Guillaume Pirou
** Last update Sun Apr 12 17:03:28 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my_mem.h"
#include "my.h"

t_opc	*get_zjmpopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[8].mnemonique);
  opc->nb_args = op_tab[8].nbr_args;
  opc->type[0] = (char)op_tab[8].type[0];
  opc->hexcode = op_tab[8].code;
  opc->nb_cycles = op_tab[8].nbr_cycles;
  opc->description = my_strdup(op_tab[8].comment);
  opc->is_paramoct = 0;
  return (opc);
}

t_opc	*get_loadindexopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[9].mnemonique);
  opc->nb_args = op_tab[9].nbr_args;
  opc->type[0] = (char)op_tab[9].type[0];
  opc->type[1] = (char)op_tab[9].type[1];
  opc->type[2] = (char)op_tab[9].type[2];
  opc->hexcode = op_tab[9].code;
  opc->nb_cycles = op_tab[9].nbr_cycles;
  opc->description = my_strdup(op_tab[9].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_storeindexopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[10].mnemonique);
  opc->nb_args = op_tab[10].nbr_args;
  opc->type[0] = (char)op_tab[10].type[0];
  opc->type[1] = (char)op_tab[10].type[1];
  opc->type[2] = (char)op_tab[10].type[2];
  opc->hexcode = op_tab[10].code;
  opc->nb_cycles = op_tab[10].nbr_cycles;
  opc->description = my_strdup(op_tab[10].comment);
  opc->is_paramoct = 1;
  return (opc);
}

t_opc	*get_forkopcode()
{
  t_opc	*opc;

  if ((opc = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  opc->keyword = my_strdup(op_tab[11].mnemonique);
  opc->nb_args = op_tab[11].nbr_args;
  opc->type[0] = (char)op_tab[11].type[0];
  opc->hexcode = op_tab[11].code;
  opc->nb_cycles = op_tab[11].nbr_cycles;
  opc->description = my_strdup(op_tab[11].comment);
  opc->is_paramoct = 0;
  return (opc);
}
