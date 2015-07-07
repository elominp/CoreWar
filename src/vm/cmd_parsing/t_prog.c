/*
** t_prog.c for  in /home/querat_g/corewar/src/vm/cmd_parsing
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:35:29 2015 gwendal querat
** Last update Sun Apr 12 20:39:50 2015 adrien schmouker
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"

t_prog		*add_elem_to_t_prog(t_prog *progs)
{
  t_prog	*res;
  t_prog	*tmp;

  if ((progs == NULL))
    {
      if ((res = gbgc_malloc(NULL, sizeof(t_prog))) == NULL)
	return (NULL);
      clear_prog_struct(res);
      res->next = NULL;
      return (res);
    }
  tmp = progs;
  while (tmp->next)
    tmp = tmp->next;
  if ((res = gbgc_malloc(NULL, sizeof(t_prog))) == NULL)
    return (NULL);
  res->next = NULL;
  tmp->next = res;
  return (progs);
}

t_prog		*last_elem(t_prog *progs)
{
  t_prog	*tmp;

  tmp = progs;
  if (tmp == NULL)
    return (NULL);
  while (tmp->next)
    tmp = tmp->next;
  return (tmp);
}

int	has_path(t_prog *prog)
{
  if (!prog || !prog->path)
    return (0);
  return (1);
}

void    display_t_prog(t_prog *cur)
{
  if (cur == NULL)
    return;
  while ((cur))
    {
      my_printf("maillon suivant > %x\n",
                (cur->next != NULL) ? &cur->next : 0);
      my_printf("id du programme > %d\n", cur->id);
      my_printf("adresse de depart du programme > %d\n", cur->adress);
      my_printf("path du programme > %s\n\n"
                "--------------------------------------------------\n"
                "\n",
                cur->path ? cur->path : "no path");
      cur = cur->next;
    }
  return;
}
