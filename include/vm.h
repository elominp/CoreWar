/*
** vm.h for corewar in /home/schmou_a/Progelem/corewar/corewar/include
** 
** Made by adrien schmouker
** Login   <schmou_a@epitech.net>
** 
** Started on  Sun Apr 12 21:17:22 2015 adrien schmouker
** Last update Sun Apr 12 22:09:23 2015 adrien schmouker
*/

#ifndef VM_H_
# define VM_H_

# include "champion.h"

# define FORK            0xc
# define LFORK           0xf
# define ZJMP            0x9
# define LIVE            0x1
# define ERROR		0
# define SUCCESS	1
# define UNDEFINED	-1
# define MAGIC_SIZE	4
# define HEADER_OFFSET	(COMMENT_LENGTH + PROG_NAME_LENGTH + 8)
# define DUMP_FILE	"./dump.mem"
# define END_GAME	2
# define DED		0

typedef struct s_prog
{
  struct s_prog	*next;
  char		*path;
  int		id;
  int		adress;
  char		*bin;
  int		size;
} t_prog;

typedef struct s_argv
{
  int		nb_progs;
  int		dump;
  struct s_prog	*progs;
} t_argv;

typedef struct s_vm
{
  int		cycle;
  int		cycle_to_die;
  int		total_cycles;
  int		live_count;
  int		nb_live;
  int		dump;
  struct s_chp	*champs;
  char		*mem;
  int		win_gid;
} t_vm;

typedef struct s_param
{
  char	bytecode;
  int	val[4];
  int	flip[4];
  char	type[4];
  int	*reg[4];
} t_param;

int	already_assigned_adress(t_prog *prog, t_prog *cmp);
int	assign_default_adress(t_prog *cur, int nb_progs, int *i);
int	assign_adress(t_prog *prog, int nb_progs);

int	already_assigned_pid(t_prog *prog, int lowest, t_prog *cmp);
int	assign_id(t_prog *prog);

int	main(int ac, char **argv);
int	assign_prog_id_and_adress(t_argv *args);
int	init_vm(t_argv *args);
void	clear_args_struct(t_argv *args);
void	clear_prog_struct(t_prog *prog);
int	set_dump(char **argv, int *i, int *dump);
int	set_prog_adress(char **argv, int *i, int *a);
int	set_prog_id(char **argv, int *i, int *prog_id);
int	set_prog_path(char **argv, int *i, char **adress);
t_prog	*add_elem_to_t_prog(t_prog *progs);
t_prog	*last_elem(t_prog *progs);
int	has_path(t_prog *prog);
void	display_t_prog(t_prog *cur);
int	isnum(char *str);
int	get_argv_data(char **argv, t_argv *args, t_prog *cur, int *i);
int	check_argv(char **argv, t_argv *args);
int	open_champ_file(char *path);
int	load_champ_to_memory(t_prog *cur);
int	load_files(t_argv *args);
unsigned int	chars_to_int(char *buf);
int		get_magic_code(int *code, t_prog *prog);
int		get_prog_name(char **name, t_prog *prog);
int		get_prog_comment(char **com, t_prog *prog);
int		get_prog_raw(char **raw, t_prog *prog, int size);
int	t_prog_to_chp(t_prog *prog, t_chp *champ, int *gid);
t_chp	*init_champ_structs(t_argv *args, t_prog *progs);
int	champ_to_linked_list(t_chp *champ, int nb);
int	dump_cycle_to_file(char *mem, int fd);
int	dump_hex_char(unsigned char c);
int	dump_memory_stdout(int cycle, int fd);
int	write_champ(t_chp *champ, char *mem);
int	load_champs_to_vm(t_vm *vm, t_chp *champs);
int	circ(int cpt);
int	valid_reg(int reg);
void	my_memcpy_circ(char *mem, char *buf, int size, int *i);
int	buf_to_int(char *buf, int size);
int	get_param_size(char code);
int	get_param(t_vm *vm, t_chp *cur, char code);
void	get_bytecode(char bytecode, char *type);
int	no_bytecode_inst(char hexcode);
void	exec_live(t_chp *cur, t_vm *vm, t_param *par);
void	exec_zjmp(t_chp *cur, t_param *par, int pc_save);
void	exec_instruction_no_code(t_chp *cur, t_vm *vm,
				 t_param *par, int pc_save);
void	exec_ld(t_chp *cur, t_vm *vm,
		t_param *par, int pc_save);
void	exec_st(t_chp *cur, t_vm *vm,
		t_param *par, int pc_save);
void	exec_add(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save);
void	exec_sub(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save);
void	exec_and(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save);
void	exec_or(t_chp *cur, t_vm *vm,
		t_param *par, int pc_save);
void	exec_xor(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save);
void	exec_sti(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save);
void	exec_lld(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save);
void	exec_lldi(t_chp *cur, t_vm *vm,
		  t_param *par, int pc_save);
void	exec_aff(t_chp *cur, t_vm *vm,
		 t_param *par, int pc_save);
void	exec_instruction_coded(t_chp *cur, t_vm *vm,
                               t_param *par, int pc_save);
void    exec_ldi(t_chp *cur, t_vm *vm, t_param *par, int pc_save);
int	prep_instruction(t_chp *cur, t_vm *vm);
int	update_live(t_chp *cur, int cycle_to_die);
int	load_next_instruction(t_vm *vm, t_chp *cur, t_opc **op);
int	update_champs(t_vm *vm, t_chp *champs, t_opc **op);
int	clock_tick(t_vm *vm, t_chp *champs, t_opc **op);
void	my_memset(char *mem, char c, int size);
int	vm_main_loop(t_vm *vm, t_chp *champs, int fd, t_opc **op);
int	load_first_instructions(t_vm *vm, t_chp *champs, t_opc **op);
int	init_vm_struct(t_vm *vm, t_argv *args, t_chp *champs, t_opc **op);
int	fill_champs_registers(t_chp *champs, t_vm *vm);
int	init_vm(t_argv *args);
int	assign_prog_id_and_adress(t_argv *args);
int	not_enough_ram();
void    display_end_game(t_vm *vm, t_chp *champs);
t_chp   *get_winner(int win, t_chp *champs);
void	write_to_circ_mem(void *src, void *mem, int pos, int size);
int     one_gid_left(t_chp *champs, t_vm *vm);

#endif /* !VM_H_ */
