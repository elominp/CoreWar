/*
** hashtable.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:03:45 2015 Guillaume Pirou
** Last update Sun Apr 12 17:03:46 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "hashtable.h"
#include "listes.h"
#include "my_mem.h"

void		destroyhashtable(t_htb *tab)
{
  unsigned int	i;

  if (tab == NULL || tab->data == NULL)
    return;
  i = 0;
  while (i < tab->size)
    freelist(tab->data[i++], hasht_del);
}

void		init_idata(t_mls *first, void *size)
{
  size_t	len;

  if (first == NULL || size == NULL)
    return;
  len = *((size_t *)size);
  first->item = gbgc_calloc(len);
}

void		init_fdata(t_htb *hash, unsigned int count)
{
  unsigned int	i;

  if (hash == NULL)
    return;
  i = 0;
  if ((hash->data = gbgc_malloc(NULL, sizeof(t_htb) * count)) == NULL)
    return;
  while (i < count)
    hash->data[i++] = createlist(NULL, NULL);
}

t_htb	*createhashtable(unsigned int count)
{
  t_htb	*hash;

  if (!count || (hash = gbgc_malloc(NULL, sizeof(t_htb))) == NULL)
    return (NULL);
  init_fdata(hash, count);
  if (hash->data == NULL)
    return (NULL);
  hash->size = count;
  return (hash);
}
