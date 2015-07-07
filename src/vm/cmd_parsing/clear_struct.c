/*
** clear_struct.c for  in /home/querat_g/corewar/src/vm/cmd_parsing
** 
** Made by gwendal querat
** Login   <querat_g@epitech.net>
** 
** Started on  Sun Apr 12 17:35:03 2015 gwendal querat
** Last update Sun Apr 12 20:39:29 2015 adrien schmouker
*/

#include <stdlib.h>
#include "opcodes.h"
#include "my.h"
#include "my_mem.h"
#include "my_printf.h"
#include "vm.h"

void	clear_args_struct(t_argv *args)
{
  args->nb_progs = 0;
  args->dump = -1;
  args->progs = NULL;
}

void	clear_prog_struct(t_prog *prog)
{
  if (prog == NULL)
    return;
  prog->path = NULL;
  prog->id = -1;
  prog->adress = -1;
  prog->next = NULL;
}
