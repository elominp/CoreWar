/*
** write_champion.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:27:36 2015 Guillaume Pirou
** Last update Sun Apr 12 17:27:37 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "my.h"
#include "asm.h"
#include "file.h"
#include "champion.h"
#include "my_mem.h"

void		my_fpadding(char c, size_t count, t_fle *file)
{
  size_t	i;
  char		*tab;

  if (file == NULL || (tab = gbgc_malloc(NULL, count)) == NULL)
    return;
  i = 0;
  while (i < count)
    tab[i++] = c;
  my_fwrite(tab, 1, count, file);
}

int	write_header(t_hdr *header, t_fle *file)
{
  t_hdr	*dup;

  if (header == NULL || file == NULL ||
      (dup = (t_hdr *)my_ptrdup(header, sizeof(t_hdr))) == NULL)
    return (0);
  nflip_endian(&(dup->magic_code), sizeof(int));
  nflip_endian(&(dup->prog_size), sizeof(int));
  my_fwrite(&(dup->magic_code), 1, 4, file);
  my_fwrite(dup->name, 1, PROG_NAME_LENGTH, file);
  my_fwrite(&(dup->prog_size), 1, 4, file);
  my_fwrite(dup->comment, 1, COMMENT_LENGTH, file);
  show_header(header);
  gbgc_free(NULL, dup);
  return (1);
}

int	write_opcs(t_opc **bin, t_fle *file)
{
  int	i;
  int	j;

  if (bin == NULL)
    return (0);
  i = -1;
  while (bin[++i] != NULL)
    {
      if (my_strcmp(bin[i]->keyword, ".code"))
	{
	  my_fwrite(&(bin[i]->hexcode), 1, 1, file);
	  if (bin[i]->is_paramoct)
	    {
	      my_fwrite(&(bin[i]->param_oct), 1, 1, file);
	      j = 1;
	    }
	  else
	    j = 0;
	  my_fwrite(bin[i]->args, 1, (bin[i]->size - (1 + j)), file);
	}
      else
	my_fwrite(bin[i]->args, 1, bin[i]->size, file);
    }
  return (1);
}

void	free_opc(t_opc *opc)
{
  if (opc != NULL)
    {
      gbgc_free(NULL, opc->args);
      gbgc_free(NULL, opc);
    }
}

int	write_champion(t_chp *chp, char *filename)
{
  t_fle	*file;

  if (chp == NULL || filename == NULL ||
      (file = my_fopen(filename, O_WRONLY)) == NULL ||
      !write_header(&(chp->header), file) ||
      !write_opcs(chp->bin, file))
    return (0);
  my_fclose(file);
  free_champ(chp);
  return (1);
}
