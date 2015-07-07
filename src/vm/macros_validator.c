/*
** macros_validator.c for  in /home/querat_g/corewar/src/vm
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:36:57 2015 gwendal querat
** Last update Sun Apr 12 17:37:07 2015 gwendal querat
*/

#include "my.h"
#include "opcodes.h"

int     macros_validator()
{
  if (IDX_MOD < 1	||
      CYCLE_TO_DIE < 1	||
      CYCLE_DELTA < 1	||
      NBR_LIVE < 1)
    return (0);
  return (1);
}
