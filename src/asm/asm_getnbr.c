/*
** asm_getnbr.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:23:50 2015 Guillaume Pirou
** Last update Sun Apr 12 17:23:50 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"

int	asm_getnbr(char *str)
{
  int	len;
  int	out;
  char	*dup;

  if (str == NULL || (len = my_strlen(str)) <= 0)
    return (0);
  if (len > 2 && str[0] == '0' && str[1] == 'x')
    {
      if ((dup = my_strdup(str + 2)) == NULL)
	return (0);
      out = my_getnbr_base(my_strupcase(dup), "0123456789ABCDEF");
      gbgc_free(NULL, dup);
      return (out);
    }
  return (my_getnbr_base(str, "0123456789"));
}
