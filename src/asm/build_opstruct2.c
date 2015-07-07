/*
** build_opstruct2.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:24:08 2015 Guillaume Pirou
** Last update Sun Apr 12 17:24:08 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "my_mem.h"

int	is_label(char *str)
{
  return (my_strlen(str) > 1 && str[my_strlen(str) - 1] == ':');
}

t_opc	*build_opc(char **line_dta, t_htb *opcds, t_htb *labels, t_chp *champ)
{
  t_opc	*res;

  if (line_dta == NULL || (line_dta[0] == NULL) ||
      (res = gbgc_malloc(NULL, sizeof(t_opc))) == NULL)
    return (NULL);
  if ((res = my_ptrdup(hasht_getel(line_dta[0], my_strlen(line_dta[0]),
				   opcds), sizeof(t_opc))) == NULL)
    return (NULL);
  if (!fill_opstruct(res, line_dta + 1, labels, champ->header.prog_size))
    return (NULL);
  champ->header.prev_size = champ->header.prog_size;
  champ->header.prog_size += res->size;
  return (res);
}

int	check_and_do_label(char *name, t_htb *lbls, t_chp *chp)
{
  if (name == NULL || lbls == NULL || chp == NULL || my_strlen(name) <= 1)
    return (0);
  if (!is_label(name))
    return (0);
  name[my_strlen(name) - 1] = '\0';
  if (hasht_getel(name, my_strlen(name), lbls) != NULL)
    return (0);
  hasht_addel(name, my_strlen(name), lbls,
	      my_ptrdup(&chp->header.prog_size, sizeof(int)));
  return (1);
}

t_opc	**first_pass_init(int *i, int *r_sze, int *prog_size)
{
  t_opc **res;

  (*i) = -1;
  (*r_sze) = 1;
  if (prog_size != NULL)
    *prog_size = 0;
  if ((res = gbgc_malloc(NULL, sizeof(t_opc *))) == NULL)
    return (NULL);
  res[0] = NULL;
  return (res);
}

char	**delete_comment(char **line)
{
  int	i;
  int	j;

  if (line == NULL)
    return (NULL);
  i = -1;
  while (line[++i] != NULL)
    {
      j = -1;
      while (line[i][++j])
	{
	  if (line[i][j] == COMMENT_CHAR || line[i][j] == ';')
	    {
	      line[i][j] = '\0';
	      if (j > 0)
		line[i + 1] = NULL;
	      else
		line[i] = NULL;
	      return (line);
	    }
	}
    }
  return (line);
}
