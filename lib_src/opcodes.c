/*
** opcodes.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:21:40 2015 Guillaume Pirou
** Last update Sun Apr 12 17:21:40 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my_mem.h"

t_opc	**get_opcodetab()
{
  t_opc	**tab;

  if ((tab = gbgc_malloc(NULL, sizeof(t_opc *) * (CW_NB_INS + 1))) == NULL)
    return (NULL);
  tab[0] = get_liveopcode();
  tab[1] = get_loadopcode();
  tab[2] = get_storeopcode();
  tab[3] = get_additionopcode();
  tab[4] = get_substractionopcode();
  tab[5] = get_andopcode();
  tab[6] = get_oropcode();
  tab[7] = get_xoropcode();
  tab[8] = get_zjmpopcode();
  tab[9] = get_loadindexopcode();
  tab[10] = get_storeindexopcode();
  tab[11] = get_forkopcode();
  tab[12] = get_longloadopcode();
  tab[13] = get_longloadindexopcode();
  tab[14] = get_longforkopcode();
  tab[15] = get_affopcode();
  tab[16] = NULL;
  return (tab);
}
