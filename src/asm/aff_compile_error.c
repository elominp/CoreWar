/*
** aff_compile_error.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:23:58 2015 Guillaume Pirou
** Last update Sun Apr 12 17:23:58 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"

void	*aff_compile_error(char **line, int line_nbr, char *error)
{
  int	i;

  i = -1;
  my_putstr2("Error : line ");
  my_putnbr_base2(line_nbr, "0123456789");
  my_putstr2("\n  ");
  while (line[++i])
    my_printf("%s ", line[i]);
  my_putstr2("\n");
  my_putstr2(error);
  return (NULL);
}
