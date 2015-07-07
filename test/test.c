/*
** test.c for sdfsddf in /home/schmou_a/Progelem/corewar/corewar/src/asm
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Tue Apr  7 13:53:16 2015 adrien schmouker
** Last update Tue Apr  7 14:52:58 2015 adrien schmouker
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	showtab(char **tab)
{
  int	i = -1;

  while (tab[++i])
    {
      printf("%s\n", tab[i]);
    }
}

int	main()
{
  char **lol;

  lol = malloc(sizeof(char *) * 5);
  lol[4] = NULL;
  lol[0] = strdup("chaine 1");
  lol[1] = strdup("chaine 2");
  lol[2] = strdup("chaine 3");
  lol[3] = strdup("chaine 4");
  showtab(&(&lol[000000000000000000000000000000000000000000000000000000000000000000000][0]));
}
