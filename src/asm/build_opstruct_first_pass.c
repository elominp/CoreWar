/*
** build_opstruct_first_pass.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:35:38 2015 Guillaume Pirou
** Last update Sun Apr 12 17:35:39 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "my_mem.h"

void    init_champ_hdr_size(t_chp *chp)
{
  if (chp != NULL)
    {
      chp->header.prog_size = 0;
      chp->header.prev_size = 0;
    }
}

int     check_reg(char **line)
{
  int   i;

  i = 0;
  while (line[i])
    {
      if (!is_label(line[i]) && line[i][0] == 'r')
        {
          if (my_atoi(line[i] + 1) < 1 || my_atoi(line[i] + 1) > 16)
            return (0);
        }
      i++;
    }
  return (1);
}

char    **frst_cdt(char **file, int i)
{
  char  **tmp;

  if (file == NULL)
    return (NULL);
  if (file[i][0] != '.' && file[i][0] != '#' && file[i][0] != ';' &&
      (tmp = my_strtok(file[i], " ,\t")) != NULL)
    return (tmp);
  return (NULL);
}

t_opc   *chk1_cdt(char **tmp, t_htb *opcs, t_chp *chp)
{
  if (tmp == NULL || opcs == NULL || chp == NULL)
    return (NULL);
  return (build_opc(delete_comment(tmp + 1), opcs, NULL, chp));
}

t_opc   **do_first_pass(char **file, t_htb *opcs, t_htb *lbls, t_chp *chp)
{
  int   i;
  char  **tmp;
  t_opc **res;
  int   r_sze;

  if ((res = first_pass_init(&i, &r_sze, &(chp->header.prog_size))) == NULL)
    return (NULL);
  while (file[++i])
    {
      if ((tmp = frst_cdt(file, i)) != NULL)
        {
          if (!check_reg(delete_comment(tmp)) ||
              (res = scd_rea(res, r_sze)) == NULL)
            return (aff_compile_error(tmp, i, "Incorrect register\n"));
          if (check_and_do_label(tmp[0], lbls, chp) != 0)
            {
              if ((res[r_sze++ - 1] = chk1_cdt(tmp, opcs, chp)) == NULL)
                return (aff_compile_error(tmp, i, "Invalid instruction\n"));
            }
          else if ((res[r_sze++ - 1] = build_opc(delete_comment(tmp), opcs,
                                                 NULL, chp)) == NULL)
            return (aff_compile_error(tmp, i, "Invalid label declaration\n"));
        }
    }
  return (res);
}
