/*
** build_opstruct_second_pass.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:35:30 2015 Guillaume Pirou
** Last update Sun Apr 12 17:35:31 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "asm.h"
#include "my_mem.h"

t_opc   **scd_rea(t_opc **res, int r_sze)
{
  if (res == NULL)
    return (NULL);
  if ((res = gbgc_realloc(res, sizeof(t_opc *) * r_sze,
                          sizeof(t_opc) * (r_sze + 1))) == NULL)
    return (NULL);
  return (res);
}

char    **do_second_pass_cdt(char **file, int i)
{
  char  **tmp;

  if (file == NULL)
    return (NULL);
  if ((tmp = my_strtok(file[i], " ,\t")) != NULL &&
      check_reg(delete_comment(tmp)) &&
      (file[i][0] != '.' || !my_strcmp(tmp[0], ".code")) &&
      file[i][0] != '#' && file[i][0] != ';')
    return (tmp);
  return (NULL);
}

t_opc   **do_second_pass_rtn(t_opc **res, int r_sze)
{
  if (res == NULL)
    return (NULL);
  if ((res = gbgc_realloc(res, sizeof(t_opc *) * r_sze,
                          sizeof(t_opc) * (r_sze + 1))) == NULL)
    return (NULL);
  res[r_sze - 1] = NULL;
  return (res);
}

t_opc   **do_second_pass(char **file, t_htb *opcs, t_htb *lbls, t_chp *chp)
{
  int   i;
  char  **tmp;
  t_opc **res;
  int   r_sze;

  if ((res = first_pass_init(&i, &r_sze, NULL)) == NULL)
    return (NULL);
  init_champ_hdr_size(chp);
  while (file[++i])
    {
      if ((tmp = do_second_pass_cdt(file, i)) != NULL)
        {
          if ((res = scd_rea(res, r_sze)) == NULL)
            return (aff_compile_error(tmp, i, "Malloc failed\n"));
          if (is_label(tmp[0]))
            {
              if ((res[r_sze++ - 1] = scd_bld1(tmp, opcs, lbls, chp)) == NULL)
                return (aff_compile_error(tmp, i, "Incorrect label\n"));
            }
          else if ((res[r_sze++ - 1] = scd_bld2(tmp, opcs, lbls, chp)) == NULL)
            return (aff_compile_error(tmp, i, "Incorrect label\n"));
          free_strtab(tmp);
        }
    }
  return (do_second_pass_rtn(res, r_sze));
}
