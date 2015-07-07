/*
** str_to_wordtab.h for corewar in /home/schmou_a/Progelem/corewar
**
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
**
** Started on  Fri Mar 27 16:03:25 2015 adrien schmouker
** Last update Sun Apr 12 10:07:40 2015 guigui
*/

#ifndef STR_TO_WORDTAB_H_
# define STR_TO_WORDTAB_H_

struct  s_my_wd
{
  int   nb_words;
  char  *str;
  char  **my_wordtab;
};
struct          s_my_lwd
{
  struct        s_my_lwd *prev;
  struct        s_my_lwd *next;
  char          *str;
};

typedef struct s_my_wd t_my_wd;
typedef struct s_my_lwd t_my_lwd;

#endif /* !STR_TO_WORDTAB_H_ */
