/*
** hash_opcode.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:25:15 2015 Guillaume Pirou
** Last update Sun Apr 12 17:25:15 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "opcodes.h"
#include "hashtable.h"

void	free_optab(t_opc **tab)
{
  int	i;

  if (tab == NULL)
    return;
  i = -1;
  while (tab[++i] != NULL)
    gbgc_free(NULL, tab[i]);
  gbgc_free(NULL, tab);
}

t_htb	*get_ophashtab()
{
  t_opc	**tab;
  t_htb	*htab;

  if ((tab = get_opcodetab()) == NULL || (htab = createhashtable(32)) == NULL)
    return (NULL);
  hasht_addel(tab[0]->keyword, my_strlen(tab[0]->keyword), htab, tab[0]);
  hasht_addel(tab[1]->keyword, my_strlen(tab[1]->keyword), htab, tab[1]);
  hasht_addel(tab[2]->keyword, my_strlen(tab[2]->keyword), htab, tab[2]);
  hasht_addel(tab[3]->keyword, my_strlen(tab[3]->keyword), htab, tab[3]);
  hasht_addel(tab[4]->keyword, my_strlen(tab[4]->keyword), htab, tab[4]);
  hasht_addel(tab[5]->keyword, my_strlen(tab[5]->keyword), htab, tab[5]);
  hasht_addel(tab[6]->keyword, my_strlen(tab[6]->keyword), htab, tab[6]);
  hasht_addel(tab[7]->keyword, my_strlen(tab[7]->keyword), htab, tab[7]);
  hasht_addel(tab[8]->keyword, my_strlen(tab[8]->keyword), htab, tab[8]);
  hasht_addel(tab[9]->keyword, my_strlen(tab[9]->keyword), htab, tab[9]);
  hasht_addel(tab[10]->keyword, my_strlen(tab[10]->keyword), htab, tab[10]);
  hasht_addel(tab[11]->keyword, my_strlen(tab[11]->keyword), htab, tab[11]);
  hasht_addel(tab[12]->keyword, my_strlen(tab[12]->keyword), htab, tab[12]);
  hasht_addel(tab[13]->keyword, my_strlen(tab[13]->keyword), htab, tab[13]);
  hasht_addel(tab[14]->keyword, my_strlen(tab[14]->keyword), htab, tab[14]);
  hasht_addel(tab[15]->keyword, my_strlen(tab[15]->keyword), htab, tab[15]);
  hasht_addel(".code", 5, htab, get_rawopcode());
  return (htab);
}
