/*
** asm.h for asm in /home/schmou_a/Progelem/corewar/corewar/include
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Apr 12 21:14:20 2015 adrien schmouker
** Last update Sun Apr 12 21:14:21 2015 adrien schmouker
*/

#ifndef ASM_H_
# define ASM_H_
# include "file.h"
# include "hashtable.h"

struct	s_file_to_mem
{
  char	**data;
  t_fle	*file;
};
union	s_lng
{
  long	data;
  char	tab[sizeof(long)];
};
struct	s_prm
{
  int	size;
  int	pos;
  char	*arg;
  char	*dest;
  t_htb	*lbl;
};

typedef struct s_prm t_prm;
typedef struct s_file_to_mem t_ftm;
typedef union s_lng t_lng;

char	**get_asmline(t_fle *);
int	asm_getnbr(char *);
t_ftm	*file_to_mem(char *);
int	write_champion(t_chp *, char *);
t_htb	*get_ophashtab();
t_opc   *build_opc(char **, t_htb *, t_htb *, t_chp *);
t_chp	*fill_champ(char **, t_htb *, t_htb *);
int     fill_header(char **, t_hdr *, int *);
int	is_hexachar(char);
int	is_validarg(char *);
int	get_nbargs(char **);
int	calc_args_onesize(char, char *);
int	calc_args_allsize(t_opc *, char **);
int	is_prmlabel(char *);
int	set_param(t_prm *);
int	calc_arg_offset(int, int *);
void   	show_tab(void *, size_t);
int	first_pass(t_opc *, char **);
char	calc_param_oct(char **);
void	add_three_args_prm(t_prm *, int, int, char *);
void	add_rest_args_prm(t_prm *, char *, t_htb *);
int	second_pass(t_opc *, char **, t_htb *, int);
int	fill_opstruct(t_opc *, char **, t_htb *, int);
int	is_label(char *);
t_opc	*build_opc(char **, t_htb *, t_htb *, t_chp *);
int	check_and_do_label(char *, t_htb *, t_chp *);
t_opc	**first_pass_init(int *, int *, int *);
char	**delete_comment(char **);
t_opc	**do_first_pass(char **, t_htb *, t_htb *, t_chp *);
t_opc	**do_second_pass(char **, t_htb *, t_htb *, t_chp *);
t_opc	**my_build_bin(char **, t_htb *, t_chp *);
void    *aff_compile_error(char **, int , char *);
void    free_opctab(t_opc **);
void    free_header(t_hdr *);
void    free_champ(t_chp *);
void    free_opc(t_opc *);
t_opc   **do_first_pass(char **, t_htb *, t_htb *, t_chp *);
t_opc   *chk1_cdt(char **, t_htb *, t_chp *);
char    **frst_cdt(char **, int);
int     check_reg(char **);
void    init_champ_hdr_size(t_chp *);
t_opc   **do_second_pass(char **, t_htb *, t_htb *, t_chp *);
t_opc   **scd_rea(t_opc **, int);
char    **do_second_pass_cdt(char **, int);
t_opc   **do_second_pass_rtn(t_opc **, int);
t_opc   *scd_bld1(char **, t_htb *, t_htb *, t_chp *);
t_opc   *scd_bld2(char **, t_htb *, t_htb *, t_chp *);
int	verif_file(char *);

#endif /* !ASM_H_ */
