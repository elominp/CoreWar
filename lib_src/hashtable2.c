/*
** hashtable2.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:03:51 2015 Guillaume Pirou
** Last update Sun Apr 12 21:27:44 2015 adrien schmouker
*/

#include <stdlib.h>
#include "hashtable.h"
#include "listes.h"
#include "my_printf.h"
#include "my_mem.h"
#include "my.h"

int		hashnoct(void *ptr, size_t len, size_t ref)
{
  unsigned int	i;
  unsigned int	key;
  char		*tab;

  if (ptr == NULL || !len || !ref)
    return (-1);
  i = 0;
  key = 0;
  tab = (char *)ptr;
  while (i < len)
    key += (((i / 2) * 2) == i) ? tab[i++] : -tab[i++];
  return (key % ref);
}

void   	hasht_wel(t_mls *lst, void *data)
{
  if (data == NULL || data == NULL)
    return;
  lst->item = data;
}

int    	hasht_addel(void *key, size_t size_key, t_htb *htab, void *data)
{
  int  	idx;
  t_hdt	*hdata;

  if (key == NULL || data == NULL || htab == NULL || !htab->size || !size_key
      || (idx = hashnoct(key, size_key, htab->size)) < 0 ||
      (hdata = gbgc_malloc(NULL, sizeof(t_hdt))) == NULL)
    return (MERROR);
  hdata->data = data;
  hdata->key = my_ptrdup(key, size_key);
  hdata->size = size_key;
  return (list_addel(htab->data[idx], hdata, hasht_wel));
}

void   	*hasht_getel(void *key, size_t size_key, t_htb *htab)
{
  t_mls	*cpy;
  int  	idx;
  t_hdt	*data;

  if (key == NULL || !size_key || htab == NULL || htab->data == NULL ||
      (idx = hashnoct(key, size_key, htab->size)) < 0)
    return (NULL);
  if ((cpy = htab->data[idx]->next) == NULL)
    return (NULL);
  while (cpy != NULL)
    {
      data = cpy->item;
      if (cpy->item != NULL && (data->size == size_key) &&
	  my_ptrcmp(data->key, key, size_key))
	return (data->data);
      cpy = cpy->next;
    }
  return (NULL);
}
