NAME	=	uls

CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g

SRCD	=	src
INCD	=	inc
OBJD	=	obj

LMXD	=	libmx
LMXA:=	$(LMXD)/libmx.a
LMXI:=	$(LMXD)/$(INCD)

INC		=	uls.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		=	main.c \
			mx_flag_check.c \
			mx_error_no_such.c \
			mx_lstat_fill.c \
			mx_get_owner.c \
			mx_get_mtime.c \
			mx_get_group.c \
			mx_get_permission.c \
			mx_get_perm_type.c \
			mx_get_name.c \
			mx_get_plink.c \
			mx_get_size.c \
			mx_get_perm_10.c \
			mx_get_args.c \
			mx_get_winsize.c \
			mx_output_error.c \
			mx_output_files.c \
			mx_push_stat.c \
			mx_output_folders.c \
			mx_get_dirlist.c \
			mx_namejoin.c \
			mx_get_total.c \
			mx_flag_F.c \
			mx_R.c \
			mx_t_uls_out_init.c \
			mx_sorty.c \
			mx_uls_cleaner.c \
			mx_cat_out.c \
			mx_1_out.c \
			mx_multicol_out.c \
			mx_def_space.c \
			mx_get_num_files.c \
			mx_struct_index.c \
			mx_long_out.c \
			mx_slong_out.c \
			mx_space.c \
			mx_flong_out.c \
			mx_get_max_group.c \
			mx_get_max_size.c \
			mx_output_total.c \
			mx_print_nonprint_str.c \
			mx_print_dname.c \
			mx_error_pd.c \
			mx_push_dir.c \
			mx_sort_dirs.c \
			mx_sort_dirs_ascii.c \
			mx_sort_dirs_size.c \
			mx_sort_dirs_utime.c \
			mx_sort_dirs_time.c \
			mx_ascii_sort_list.c \
			mx_data_swap.c \
			mx_char_swap.c \
			mx_int_swap.c \
			mx_time_swap.c \
			mx_size_swap.c \
			mx_sort_files.c \
			mx_sort_files_size.c \
			mx_sort_files_ascii.c \
			mx_sort_files_time.c \
			mx_m_out.c \


SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(LMXA) $(NAME)

$(NAME): $(OBJS)
	@clang $(CFLG) $(OBJS) -L$(LMXD) -lmx -o $@
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) -I$(LMXI)
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

$(LMXA):
	@make -sC $(LMXD)

clean:
	@make -sC $(LMXD) $@
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@make -sC $(LMXD) $@
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install
