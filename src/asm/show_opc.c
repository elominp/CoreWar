/*
** show_opc.c for asm in /home/pirou_g/corewar/src/asm
** 
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
** 
** Started on  Sun Apr 12 17:25:39 2015 Guillaume Pirou
** Last update Sun Apr 12 17:25:40 2015 Guillaume Pirou
*/

#include "my.h"
#include "opcodes.h"
#include "my_printf.h"

void	show_opcode(t_opc *opcode)
{
  my_printf(" KEYWORD :  \"%s\"\n", opcode->keyword);
  my_printf(" NB_ARGS :  \"%d\"\n", opcode->nb_args);
  my_printf(" TYPE    :  \"%s\"\n", opcode->type);
  my_printf(" ARGS    :  \"%s\"\n", opcode->args);
  my_printf(" HEXCODE :  \"%x\"\n", opcode->hexcode);
  my_printf(" NB_CYCL :  \"%d\"\n", opcode->nb_cycles);
  my_printf(" DESC    :  \"%s\"\n", opcode->description);
}
