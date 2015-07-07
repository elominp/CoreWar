/*
** fill_header.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:24:35 2015 Guillaume Pirou
** Last update Sun Apr 12 17:24:36 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "champion.h"
#include "my_mem.h"

void            show_header(t_hdr *header)
{
  my_printf("  MAGIC CODE = %x\n  NAME = \"%s\"\n",
	    header->magic_code, header->name);
  my_printf("  PROG SIZE = %d\n  COMMENT = \"%s\"\n",
	    header->prog_size, header->comment);
}

char            *get_comment(char *line, int *cursor)
{
  char          **line_tokens;
  char          *comment;

  if ((line_tokens = my_strtok(line, "\"")) == NULL)
    return (NULL);
  if (tab_len(line_tokens) > 1)
    {
      if ((comment = gbgc_calloc(sizeof(char) * COMMENT_LENGTH + 1)) == NULL)
        return (NULL);
      (*cursor)++;
      comment = my_strncpy2(comment, line_tokens[1], COMMENT_LENGTH);
      return (comment);
    }
  return (NULL);
}

char            *get_name(char *line, int *cursor)
{
  char          **line_tokens;
  char          *name;

  if ((line_tokens = my_strtok(line, "\"")) == NULL)
    return (NULL);
  if (tab_len(line_tokens) > 1)
    {
      if ((name = gbgc_calloc(sizeof(char) * PROG_NAME_LENGTH + 1)) == NULL)
        return (NULL);
      (*cursor)++;
      name = my_strncpy2(name, line_tokens[1], PROG_NAME_LENGTH);
      return (name);
    }
  return (NULL);
}

int             fill_header(char **file, t_hdr *hdr, int *i)
{
  if ((tab_len(file)) < 2)
    {
      my_putstr("file is too short\n");
      return (0);
    }
  hdr->prog_size = 0;
  if ((hdr->magic_code = COREWAR_EXEC_MAGIC) < 0)
    return (0);
  hdr->name = get_name(file[(*i)], i);
  hdr->comment = get_comment(file[(*i)], i);
  return (1);
}
