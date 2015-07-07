/*
** convert_base.c for corewar in /home/pirou_g/corewar/lib_src
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:02:29 2015 Guillaume Pirou
** Last update Sun Apr 12 17:02:31 2015 Guillaume Pirou
*/

#include "my.h"

char	*convert_base(char *nbr, char *base_from, char *base_to)
{
  int	nb;
  char	*tab;

  nb = my_getnbr_base(nbr, base_from);
  tab = (char *)my_strnbr(nb, base_to);
  return (tab);
}
