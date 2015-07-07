ASM		= asm/asm

VM		= corewar/corewar

DSM		= desasm/desasm

LIB		= libmy.a

AR_RC		= ar rc

RANLIB		= ranlib

LIB_SRCS	= bocal/op.c \
		  lib_src/convert_base.c \
		  lib_src/get_next_line.c \
		  lib_src/tab_len.c \
		  lib_src/get_option.c \
		  lib_src/is_option.c \
		  lib_src/listes.c \
		  lib_src/listes2.c \
		  lib_src/my_atoi.c \
		  lib_src/my_countnb_b.c \
		  lib_src/my_epur_str.c \
		  lib_src/my_find_prime_sup.c \
		  lib_src/my_get_el.c \
		  lib_src/my_getnbr.c \
		  lib_src/my_getnbr_base.c \
		  lib_src/my_isneg.c \
		  lib_src/my_is_prime.c \
		  lib_src/my_malloc.c \
		  lib_src/my_malloc2.c \
		  lib_src/my_parse.c \
		  lib_src/my_power_it.c \
		  lib_src/my_power_rec.c \
		  lib_src/my_printf.c \
		  lib_src/my_put.c \
		  lib_src/my_putblank.c \
		  lib_src/my_putchar.c \
		  lib_src/my_putchar2.c \
		  lib_src/my_putint.c \
		  lib_src/my_put_nbr.c \
		  lib_src/my_putnbr_base.c \
		  lib_src/my_putnbr_base2.c \
		  lib_src/my_putptr.c \
		  lib_src/my_putstr.c \
		  lib_src/my_putstr2.c \
		  lib_src/my_revstr.c \
		  lib_src/my_round.c \
		  lib_src/my_showmem.c \
		  lib_src/my_showstr.c \
		  lib_src/my_show_wordtab.c \
		  lib_src/my_sort_int_tab.c \
		  lib_src/my_square_root.c \
		  lib_src/my_strcapitalize.c \
		  lib_src/my_strcat.c \
		  lib_src/my_strcmp.c \
		  lib_src/my_strcpy.c \
		  lib_src/my_strdup.c \
		  lib_src/my_str_isalpha.c \
		  lib_src/my_str_islower.c \
		  lib_src/my_str_isnum.c \
		  lib_src/my_str_isprintable.c \
		  lib_src/my_str_isupper.c \
		  lib_src/my_strlcat.c \
		  lib_src/my_strlen.c \
		  lib_src/my_strlowcase.c \
		  lib_src/my_strnbr.c \
		  lib_src/my_strncat.c \
		  lib_src/my_strncmp.c \
		  lib_src/my_strncpy.c \
		  lib_src/my_strstr.c \
		  lib_src/my_strtab.c \
		  lib_src/my_strtok.c \
		  lib_src/my_str_to_wordtab.c \
		  lib_src/my_strupcase.c \
		  lib_src/my_swap.c \
		  lib_src/my_uppercase.c \
		  lib_src/worknb.c \
		  lib_src/file/get_ram.c \
		  lib_src/file/my_fdup.c \
		  lib_src/file/my_fgeti.c \
		  lib_src/file/my_fgetsize.c \
		  lib_src/file/my_fread.c \
		  lib_src/file/my_opcl.c \
		  lib_src/file/my_fwrite.c \
		  lib_src/opcodes.c \
		  lib_src/get_opc1.c \
		  lib_src/get_opc2.c \
		  lib_src/get_opc3.c \
		  lib_src/get_opc4.c \
		  lib_src/print_binary.c \
		  lib_src/flip_endian.c \
		  lib_src/tab_len.c \
		  lib_src/gnl_querat_g.c \
		  lib_src/gen_flip_endian.c \
		  lib_src/hashtable.c \
		  lib_src/hashtable2.c \
		  lib_src/hashtable3.c \
		  lib_src/my_memcpy.c \
		  lib_src/my_ptrcmp.c \
		  lib_src/my_ptrdup.c \
		  lib_src/my_strndup.c

ASM_SRCS	= src/asm/get_asmline.c \
		  src/asm/asm_getnbr.c \
		  src/asm/fill_champ.c \
		  src/asm/file_to_mem.c \
		  src/asm/fill_header.c \
		  src/asm/main.c \
		  src/asm/free_champ.c \
		  src/asm/write_champion.c \
		  src/asm/show_opc.c \
		  src/asm/build_opstruct.c \
		  src/asm/build_opstruct2.c \
		  src/asm/hash_opcode.c \
		  src/asm/fill_opstruct.c \
		  src/asm/compile_rc_fill_opstruct.c \
		  src/asm/fill_opstruct2.c \
		  src/asm/aff_compile_error.c \
		  src/asm/build_opstruct_first_pass.c \
		  src/asm/build_opstruct_second_pass.c \
		  src/asm/fill_opstruct3.c \
		  src/asm/verif_file.c

VM_SRCS		= src/vm/main.c \
		  src/vm/cmd_parsing/argv_to_mem.c \
		  src/vm/cmd_parsing/clear_struct.c \
		  src/vm/cmd_parsing/set_from_argv.c \
		  src/vm/cmd_parsing/t_prog.c \
		  src/vm/assign_adress.c \
		  src/vm/assign_pid.c \
		  src/vm/load_files.c \
		  src/vm/champ_structs.c \
		  src/vm/get_prog_data.c \
		  src/vm/get_vm_data.c \
		  src/vm/dump.c \
		  src/vm/exec_instructions1.c \
		  src/vm/exec_instructions2.c \
		  src/vm/exec_instructions3.c \
		  src/vm/exec_instructions4.c \
		  src/vm/exec_instructions5.c \
		  src/vm/conf_instruction.c \
		  src/vm/config_vm.c \
		  src/vm/config_vm2.c \
		  src/vm/reg_mem_vm.c \
		  src/vm/load_champs.c

DSM_SRCS	= desasm/main.c \
		  desasm/desasm.c

LIB_OBJS	= $(LIB_SRCS:.c=.o)

VM_OBJS		= $(VM_SRCS:.c=.o)

ASM_OBJS	= $(ASM_SRCS:.c=.o)

DSM_OBJS	= $(DSM_SRCS:.c=.o)

SAVS_HDS	= include/asm.h~ \
		  include/champion.h~ \
		  include/file.h~ \
		  include/format.h~ \
		  include/hashtable.h~ \
		  include/listes.h~ \
		  include/my.h~ \
		  include/my_mem.h~ \
		  include/my_printf.h~ \
		  include/opcodes.h~ \
		  include/str_to_wordtab.h~ \
		  include/vm.h~

SAVS_LIB	= $(LIB_SRCS:.c=.c~)

SAVS_ASM	= $(ASM_SRCS:.c=.c~)

SAVS_VM		= $(VM_SRCS:.c=.c~)

SAVS_DSM	= $(DSM_SRCS:.c=.c~)

RM		= rm -f

CC		= gcc

CFLAGS		= -Wall -Wextra -I./include -I./bocal

LDFLAGS		= -lmy -L.

all:		$(LIB) $(ASM) $(DSM) $(VM)

$(LIB):		$(LIB_OBJS)
		$(AR_RC) $(LIB) $(LIB_OBJS)
		$(RANLIB) $(LIB)

$(ASM):		$(ASM_OBJS)
		$(CC) $(ASM_OBJS) -o $(ASM) $(CFLAGS) $(LDFLAGS)

$(VM):		$(VM_OBJS)
		$(CC) $(VM_OBJS) -o $(VM) $(CFLAGS) $(LDFLAGS)

test:
	./asm_test

clean:
		$(RM) $(LIB_OBJS)
		$(RM) $(ASM_OBJS)
		$(RM) $(VM_OBJS)
		$(RM) $(DSM_OBJS)
		$(RM) $(SAVS_LIB)
		$(RM) $(SAVS_ASM)
		$(RM) $(SAVS_VM)
		$(RM) $(SAVS_HDS)
		$(RM) $(SAVS_DSM)
		$(RM) Makefile~

fclean:		clean
		$(RM) $(VM)
		$(RM) $(ASM)
		$(RM) $(LIB)
		$(RM) $(DSM)

re:		fclean all

$(DSM):		$(LIB) $(DSM_OBJS)
		$(CC) $(DSM_OBJS) -o $(DSM) $(CFLAGS) $(LDFLAGS)

desasm:		$(DSM)

.PHONY: all clean fclean re test
