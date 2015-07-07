/*
** listes.h for libmy in /home/schmou_a/Progelem/corewar/corewar/include
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Apr 12 21:16:37 2015 adrien schmouker
** Last update Sun Apr 12 21:16:38 2015 adrien schmouker
*/

#ifndef LISTES_H_
# define LISTES_H_

# define MERROR -1
# define MFALSE  0
# define MTRUE   1

struct		s_mls
{
  void		*item;
  struct s_mls	*next;
  struct s_mls	*prev;
};

typedef struct s_mls t_mls;

int	list_freeel(t_mls *, void (*)(t_mls *));
int	list_addel(t_mls *, void *, void (*)(t_mls *, void *));
int	list_delel(t_mls *, void (*)(t_mls *));
t_mls	*createlist(void *, void (*)(t_mls *, void *));
int	freelist(t_mls *, void (*)(t_mls *));
int	printlist(t_mls *, void (*)(t_mls *));
int	ilistsort(t_mls *, int (*)(t_mls *, t_mls *));

#endif /* !LISTES_H_ */
