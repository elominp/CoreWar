/*
** hashtable.h for libmy in /home/schmou_a/Progelem/corewar/corewar/include
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Apr 12 21:16:24 2015 adrien schmouker
** Last update Sun Apr 12 21:16:25 2015 adrien schmouker
*/

#ifndef HASHTABLE_H_
# define HASHTABLE_H_
#include "listes.h"

struct		s_htb
{
  size_t	size;
  t_mls		**data;
};

struct		s_hdt
{
  size_t  	size;
  void		*data;
  void		*key;
};

typedef struct s_htb t_htb;
typedef struct s_hdt t_hdt;

t_htb	*createhashtable(unsigned int);
void   	destroyhashtable(t_htb *);
void   	*hasht_getel(void *, size_t, t_htb *);
int    	hasht_addel(void *, size_t, t_htb *, void *);
int	hasht_delel(void *, size_t, t_htb *);
void	hasht_del(t_mls *);
int    	hashnoct(void *, size_t, size_t);

#endif /* !HASHTABLE_H_ */
