/*
** my_fgeti.c for corewar in /home/pirou_g/corewar/lib_src/file
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:22:26 2015 Guillaume Pirou
** Last update Sun Apr 12 22:35:51 2015 gwendal querat
*/

#include <stdlib.h>
#include "my.h"
#include "file.h"

int	my_fgeti(t_fle *file)
{
  int	i;
  int	j;
  char	buff[12];

  i = 0;
  if (file == NULL)
    return (0);
  while (((j = my_fread(file, buff + i, 1)) > 0) &&
	 (my_isnum(buff[i]) && i++ < 11))
    buff[i + j] = '\0';
  return (my_atoi(buff));
}
