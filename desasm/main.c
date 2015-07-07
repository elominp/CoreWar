/*
** main.c for desasm in /home/guigui/CoreWar/master/corewar/desasm
** 
** Made by guigui
** Login   <guigui@epitech.net>
** 
** Started on  Fri Apr 10 16:09:34 2015 guigui
** Last update Sun Apr 12 16:52:38 2015 guigui
*/

#include <stdlib.h>
#include "op.h"
#include "my.h"
#include "desasm.h"

void	loop_desasm(int *i, t_dsm *ptr)
{
  int	*tmp;

  if (i == NULL || ptr == NULL)
    return;
  if (ptr->raw[*i] < 1 || ptr->raw[*i] > 16)
    my_printf("unknow opcode");
  else
    my_printf("%s ", op_tab[ptr->raw[*i] - 1].mnemonique);
  if (ptr->raw[*i] == 1 || ptr->raw[*i] == 9 || ptr->raw[*i] == 12 ||
      ptr->raw[*i] == 15)
    {
      tmp = (int *)(ptr->raw + *i + 1);
      nflip_endian(tmp, sizeof(int));
      my_printf("%%%d\n", *tmp);
      *i += 5;
    }
  else
    {
      *i += 1;
      *i += calc_sizes(ptr->raw[*i], ptr->raw + *i + 1) + 1;
    }
}

void	my_desasm(char *str)
{
  t_dsm	*ptr;
  int	i;

  if (str == NULL || (ptr = open_cor(str)) == NULL)
    return;
  i = 0;
  while (i < ptr->prog_size)
    loop_desasm(&i, ptr);
  free_dsm(ptr);
}

int	main(int argc, char **argv)
{
  int	i;

  if (argc > 1)
    {
      i = 0;
      while (++i < argc)
	my_desasm(argv[i]);
    }
  return (0);
}
