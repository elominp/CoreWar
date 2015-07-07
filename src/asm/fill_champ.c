/*
** fill_champ.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:24:29 2015 Guillaume Pirou
** Last update Sun Apr 12 17:24:30 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "champion.h"
#include "my_mem.h"
#include "hashtable.h"
#include "asm.h"

t_chp	*fill_champ(char **file, t_htb *opc, t_htb *lbl)
{
  t_chp	*res;
  int	i;
  t_opc	**test;

  i = 0;
  if (file == NULL || opc == NULL || lbl == NULL)
    {
      my_putstr("no loaded file in memory !\n");
      return (NULL);
    }
  if ((res = gbgc_malloc(NULL, sizeof(t_chp))) == NULL)
    return (NULL);
  if ((fill_header(file, &(res->header), &i)) == 0)
    return (NULL);
  if ((test = my_build_bin(file, opc, res)) == NULL)
    return (NULL);
  res->bin = test;
  return (res);
}
