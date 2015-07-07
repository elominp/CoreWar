/*
** free_champ.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:25:03 2015 Guillaume Pirou
** Last update Sun Apr 12 17:25:04 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "asm.h"
#include "file.h"
#include "champion.h"
#include "my_mem.h"

void    free_opctab(t_opc **tab)
{
  int   i;

  if (tab != NULL)
    {
      i = -1;
      while (tab[++i] != NULL)
        free_opc(tab[i]);
      gbgc_free(NULL, tab);
    }
}

void    free_header(t_hdr *hdr)
{
  if (hdr != NULL)
    {
      gbgc_free(NULL, hdr->name);
      gbgc_free(NULL, hdr->comment);
    }
}

void    free_champ(t_chp *chp)
{
  if (chp != NULL)
    {
      free_header(&(chp->header));
      free_opctab(chp->bin);
    }
}
