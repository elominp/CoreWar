/*
** gen_flip_endian.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:02:53 2015 Guillaume Pirou
** Last update Sun Apr 12 17:02:54 2015 Guillaume Pirou
*/

#include <stdlib.h>

void	swap_oct(char *a, char *b)
{
  char	c;

  if (a == NULL || b == NULL)
    return;
  c = *a;
  *a = *b;
  *b = c;
}

void		nflip_endian(void *ptr, size_t size)
{
  size_t	i;
  char		*tab;

  if (ptr == NULL || size < 2)
    return;
  i = 0;
  tab = (char *)ptr;
  while (i < (size / 2))
    {
      swap_oct(&tab[i], &tab[size - i - 1]);
      i++;
    }
}
