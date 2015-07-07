/*
** champ_structs.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:37:32 2015 gwendal querat
** Last update Sun Apr 12 20:23:02 2015 adrien schmouker
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"
#include "op.h"

int	champ_to_linked_list(t_chp *champ, int nb)
{
  int	i;

  i = 0;
  if (champ == NULL)
    return (SUCCESS);
  while (i < nb - 1)
    {
      champ[i].next = &champ[i + 1];
      i++;
    }
  return (SUCCESS);
}

int	t_prog_to_chp(t_prog *prog, t_chp *champ, int *gid)
{
  if (prog == NULL || champ == NULL || prog->bin == NULL)
    return (ERROR);
  if (((get_magic_code(&champ->header.magic_code, prog)) == ERROR)	  ||
      ((get_prog_name(&champ->header.name, prog)) == ERROR)		  ||
      ((get_prog_comment(&champ->header.comment, prog)) == ERROR)	  ||
      ((champ->header.prog_size = prog->size - HEADER_OFFSET) <= 0)	  ||
      ((get_prog_raw(&champ->raw, prog, champ->header.prog_size)) == ERROR))
    return (ERROR);
  if (((champ->pid = prog->id) < 0)	||
      ((champ->pc = prog->adress) < 0))
    return (ERROR);
  champ->next = NULL;
  champ->ticks = 0;
  champ->last_live = 0;
  champ->living = 1;
  champ->gid = (*gid)++;
  champ->carry = 1;
  return (SUCCESS);
}

t_chp		*init_champ_structs(t_argv *args, t_prog *progs)
{
  t_chp		*champs;
  t_prog	*cur;
  int		i;
  int		gid;

  i = 0;
  gid = 1;
  if ((cur = progs) == NULL || args->nb_progs < 1)
    return (NULL);
  if ((champs = gbgc_calloc(sizeof(t_chp) * args->nb_progs)) == NULL)
    return (NULL);
  while ((cur && i < args->nb_progs))
    {
      if ((t_prog_to_chp(cur, &champs[i], &gid)) == ERROR)
	return (NULL);
      cur = cur->next;
      i++;
    }
  return (champs);
}
