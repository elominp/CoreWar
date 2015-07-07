/*
** main.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:25:30 2015 Guillaume Pirou
** Last update Sun Apr 12 17:25:31 2015 Guillaume Pirou
*/

#include <stdlib.h>
#include "my.h"
#include "my_mem.h"
#include "asm.h"
#include "hashtable.h"

t_arg	*get_asm_args(int argc, char **argv)
{
  t_arg	*out;
  int	i;
  int	len;
  char	*file;

  if ((out = gbgc_malloc(NULL, sizeof(t_arg))) == NULL ||
      (out->name = gbgc_malloc(NULL, sizeof(char *) * (argc + 1))) == NULL)
    return (NULL);
  i = 0;
  out->nfiles = argc;
  while (++i < argc)
    {
      if ((len = my_strlen(argv[i])) <= 0)
	return (NULL);
      file = (argv[i][len - 1] == 's' && argv[i][len - 2] == '.') ?
	my_strdup(argv[i]) : my_strstick(argv[i], ".s");
      out->name[i - 1] = file;
    }
  out->name[argc] = NULL;
  return (out);
}

char	**separe_word(char **test)
{
  char	**word;
  int	i;

  i = 0;
  while (test[i] != NULL)
    {
      if (test[i][0])
	word = my_strtok(test[i], ",\t");
      i++;
    }
  return (word);
}

void	do_file_extension(t_chp *chp, t_fle *file)
{
  file->name[my_strlen(file->name) - 2] = '\0';
  write_champion(chp, my_strstick(file->name, ".cor"));
}

void	*main_loop(char **argv, int i, t_htb *op, t_htb *lbl)
{
  t_chp	*chp;
  t_ftm *test;

  if (!verif_file(argv[i]) || (test = file_to_mem(argv[i])) == NULL)
    {
      my_printf("file_to_mem failed !\n");
      return (NULL);
    }
  separe_word(test->data);
  if ((chp = fill_champ(test->data, op, lbl)) == NULL)
    my_printf("Compilation error\n");
  else
    do_file_extension(chp, test->file);
  return ("success");
}

int	main(int argc, char **argv)
{
  t_arg	*args;
  t_htb *op;
  t_htb	*lbl;
  int	i;

  gbgc_init();
  i = 1;
  if ((op = get_ophashtab()) == NULL || (lbl = createhashtable(101)) == NULL)
    return (0);
  if ((args = get_asm_args(argc, argv)) != NULL)
    {
      while (argv[i])
	{
	  if (main_loop(argv, i, op, lbl) == NULL)
	    return (1);
	  i++;
	}
    }
  destroyhashtable(lbl);
  destroyhashtable(op);
  gbgc_erase(NULL);
  return (0);
}
