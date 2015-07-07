/*
** my_printf.h for mysh in /home/pirou_g/minishell2/include
**
** Made by Guillaume Pirou
** Login   <pirou_g@epitech.net>
**
** Started on  Sun Feb  1 08:26:26 2015 Guillaume Pirou
** Last update Sun Apr 12 10:07:20 2015 guigui
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_
# include <stdarg.h>

struct s_data
{
  char	flag;
  int	width;
  int	precision;
  char	specifier;
};

typedef struct s_data t_data;

int	get_flags(const char *, t_data *);
int	get_width(const char *, t_data *, va_list *);
int	get_precision(const char *, t_data *, va_list *);
int	get_specifier(char , t_data *);
int	is_specifier(char);
int	is_flags(char);
int	is_width(char);
int	is_precision(char , char);
int	my_putdata(t_data *, va_list *);
int	init_data(t_data *);
int	my_isalpha(char);
int	my_parse_loop(const char *, va_list *);
int	my_parse_format(const char *, va_list *);
int	my_printf(const char *, ...);
int	my_putinteger(t_data *, va_list *);
int	my_putstring(t_data *, va_list *);
int	my_putpointer(t_data *, va_list *);
void	my_putblank(int);
int	my_putdecint(t_data *, va_list *, int);
int	my_putudecint(t_data *, va_list *, int);
int	my_putuoctint(t_data *, va_list *);
int	my_putuhexint(t_data *, va_list *, int);
int	my_ptrprintnbr(unsigned long, char *, unsigned int);
int	my_putptr(unsigned long);
char	*my_uppercase(char *);
int	my_nbchiff(long, int);
int	my_absatoi(const char *);
void	my_putzero(int);
int	my_putnbr_base(long, char *);
int	my_putunbr_base(unsigned long, char *);

#endif /* !MY_PRINTF_H_ */
