/*
** get_asmline.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:25:09 2015 Guillaume Pirou
** Last update Sun Apr 12 17:25:09 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"

char	**get_asmline(t_fle *fd)
{
  if (fd == NULL)
    return (NULL);
  return (my_strtok(get_next_line(fd), " ,"));
}
