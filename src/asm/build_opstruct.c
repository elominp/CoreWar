/*
** build_opstruct.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:23:43 2015 Guillaume Pirou
** Last update Sun Apr 12 17:23:43 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "my_mem.h"

t_opc	*scd_bld1(char **tmp, t_htb *opcs, t_htb *lbls, t_chp *chp)
{
  if (tmp == NULL || opcs == NULL || lbls == NULL || chp == NULL)
    return (NULL);
  return (build_opc(delete_comment(tmp + 1), opcs, lbls, chp));
}

t_opc	*scd_bld2(char **tmp, t_htb *opcs, t_htb *lbls, t_chp *chp)
{
  if (tmp == NULL || opcs == NULL || lbls == NULL || chp == NULL)
    return (NULL);
  return (build_opc(delete_comment(tmp), opcs, lbls, chp));
}

t_opc	**my_build_bin(char **file, t_htb *opcodes, t_chp *champ)
{
  t_htb *labels;
  t_opc	**bin;

  if ((labels = createhashtable(101)) == NULL)
    return (NULL);
  if ((bin = do_first_pass(file, opcodes, labels, champ)) == NULL)
    return (NULL);
  if ((bin = do_second_pass(file, opcodes, labels, champ)) == NULL)
    return (NULL);
  free_strtab(file);
  return (bin);
}
