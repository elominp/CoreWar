/*
** opcodes.h for opcodes in /home/guigui
**
** Made by guigui
** Login   <guigui@epitech.net>
**
** Started on  Wed Mar 18 10:32:36 2015 guigui
** Last update Sun Apr 12 10:07:34 2015 guigui
*/

#ifndef OPCODES_H_
# define OPCODES_H_
# define VM_RAMSIZE		6144
# define CW_NB_INS		16
# define T_IDX			16

# include "../bocal/op.h"

struct	s_opc
{
  char	*keyword;
  char	nb_args;
  char	type[MAX_ARGS_NUMBER];
  char	*args;
  int	size;
  int	size_args[MAX_ARGS_NUMBER];
  char	param_oct;
  char  is_paramoct;
  char	hexcode;
  int	nb_cycles;
  char	*description;
};
struct	s_hdr
{
  int	magic_code;
  char	*name;
  int	prev_size;
  int	prog_size;
  char	*comment;
};

typedef struct s_opc t_opc;
typedef struct s_hdr t_hdr;
typedef struct s_src t_src;

t_opc	*get_liveopcode();
t_opc	*get_loadopcode();
t_opc	*get_storeopcode();
t_opc	*get_additionopcode();
t_opc	*get_substractionopcode();
t_opc	*get_andopcode();
t_opc	*get_oropcode();
t_opc	*get_xoropcode();
t_opc	*get_zjmpopcode();
t_opc	*get_loadindexopcode();
t_opc	*get_storeindexopcode();
t_opc	*get_forkopcode();
t_opc	*get_longloadopcode();
t_opc	*get_longloadindexopcode();
t_opc	*get_longforkopcode();
t_opc	*get_affopcode();
t_opc	*get_rawopcode();
t_opc	**get_opcodetab();
void    show_opcode(t_opc *);

#endif /* !OPCODES_H_ */
