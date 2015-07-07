/*
** my_mem.h for mysh in /home/pirou_g/reminishell2/minishell2/include
**
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
**
** Started on  Sat Mar  7 18:19:32 2015 Guillaume Pirou
** Last update Sun Apr 12 10:07:13 2015 guigui
*/

#ifndef MY_MEM_H_
# define MY_MEM_H_

#include <stdlib.h>
#include "listes.h"

struct		s_gbgl
{
  void		*ptr;
  struct s_gbgl *next;
  struct s_gbgl *prev;
};
struct	s_arg
{
  int	nfiles;
  char	**name;
};

typedef struct s_arg t_arg;
typedef struct s_gbgl t_gbl;

void   	gbgc_init();
void   	*gbgc_malloc(t_gbl *, size_t);
void	*gbgc_calloc(size_t);
void	gbgc_freeptr(t_gbl *);
void   	*gbgc_free(t_gbl *, void *);
void   	*gbgc_realloc(void *, size_t, size_t);
void    gbgc_erase(t_gbl *);
void   	*gbgc_add(t_gbl *, void *);

#endif /* !MY_MEM_H_ */
