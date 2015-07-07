/*
** desasm.h for desasm in /home/schmou_a/Progelem/corewar/corewar/desasm
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Apr 12 21:13:12 2015 adrien schmouker
** Last update Sun Apr 12 21:13:13 2015 adrien schmouker
*/

#ifndef DESASM_H_
# define DESASM_H_

struct	s_dsm
{
  int	hexcode;
  char	*name;
  int	prog_size;
  char	*comment;
  char	*raw;
};

typedef struct s_dsm t_dsm;

t_dsm	*print_header(int, t_dsm *, int);
t_dsm	*open_cor(char *);
void	calc_cdt(int *, int *, int, char *);
int	calc_sizes(char, char *);
void	free_dsm(t_dsm *);
void	loop_desasm(int *, t_dsm *);
void	my_desasm(char *);
int	main(int, char **);

#endif /* DESASM_H_ */
