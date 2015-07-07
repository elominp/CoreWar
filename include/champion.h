/*
** champion.h for corewar in /home/guigui/CoreWar/corewar/lib_src
**
** Made by guigui
** Login   <guigui@epitech.net>
**
** Started on  Sun Mar 29 22:20:40 2015 guigui
** Last update Sun Apr 12 21:14:42 2015 adrien schmouker
*/

#ifndef CHAMPION_H_
# define CHAMPION_H_
# include "opcodes.h"
# include "file.h"

struct	s_chp
{
  int		reg[16];
  t_hdr		header;
  char		*raw;
  t_opc		**bin;
  int		pid;
  int		gid;
  int		off;
  int		pc;
  int		ticks;
  char		living;
  int		last_live;
  int		carry;
  t_opc		*inst;
  struct s_chp	*next;
};
struct	s_binary_ins
{
  char	hex;
  char	des;
  char	data[DIR_SIZE * 3];
};
struct	s_binary_sins
{
  char	hex;
  char	data[DIR_SIZE * 3];
};
struct	s_ins
{
  int	instruction;
  int	size;
  void	*raw;
};

typedef struct s_chp t_chp;
typedef struct s_binary_ins t_bin;
typedef struct s_binary_sins t_bss;
typedef struct s_ins t_ins;

void	show_header(t_hdr *);

#endif /* !CHAMPION_H_ */
