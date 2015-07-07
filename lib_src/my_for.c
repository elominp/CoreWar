/*
** my_for.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:05:19 2015 Guillaume Pirou
** Last update Sun Apr 12 17:05:22 2015 Guillaume Pirou
*/

#include <stdlib.h>

double		my_for(double start, double end, double dif,
		       double (*ptr)(double, void *))
{
  double	res;
  double	i;

  if (ptr == NULL)
    return (0);
  i = start;
  res = 0;
  while ((dif < 0) ? (i > end) : (i < end))
    {
      res = ptr(i, NULL);
      i += dif;
    }
  return (res);
}
