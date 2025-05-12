NAME = minishell

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

SRC =./cpp_map/cpp_map_add.c ./cpp_map/cpp_map_clear.c ./cpp_map/cpp_map_delete.c ./cpp_map/cpp_map_foreach.c ./cpp_map/cpp_map_get.c \
./cpp_map/cpp_map_hash_function.c ./cpp_map/cpp_map_new.c ./cpp_map/cpp_resize.c ./cpp_map/prime_nums.c ./cpp_string/cpp_str_add.c ./cpp_string/cpp_str_delete.c \
./cpp_string/cpp_str_insert.c ./cpp_string/cpp_str_new.c ./cpp_string/cpp_str_resize.c ./herdoc/herdoc_tools.c ./herdoc/herdoc.c\
./cs_list/cs_list_contains.c ./cs_list/cs_list_delete.c ./cs_list/cs_list_insert.c ./cs_list/cs_list_new.c ./cs_list/cs_list_resize.c ./cs_list/ft_memcpy.c \
./cs_list/cs_list_add.c ./ft_func/ft_strjoin.c ./ft_func/ft_strlcat.c ./ft_func/ft_strncmp.c ./ft_func/ft_strnstr.c ./ft_func/ft_substr.c ./ft_func/ft_strrchr.c \
./ft_func/ft_atoi.c ./ft_func/ft_itoa.c ./ft_func/ft_split.c ./ft_func/ft_strchr.c ./ft_func/ft_strchrlen.c ./ft_func/ft_strdup.c \
./ft_func/ft_strlen.c ./ft_func/replace_char.c ./garbage_collector/ft_calloc.c ./garbage_collector/ft_exit.c ./garbage_collector/ft_free.c \
./garbage_collector/ft_save_mem.c ./garbage_collector/mem_list.c ./get/get_next_line.c ./herdoc/create_file_name.c ./herdoc/delete_files.c\
./get/get_next_line_utils.c ./env_variable/get_env_vars/add_env_variable_token.c ./env_variable/get_env_vars/create_key_token.c \
./env_variable/get_env_vars/get_env_variable.c ./env_variable/get_env_vars/get_env_vars_heredoc.c ./env_variable/set_env_vars/set_env_checkes.c \
./env_variable/set_env_vars/set_env_variable.c ./env_variable/env_variable.c ./env_variable/split_var_token.c ./execute_cmd/execute_cmd.c \
./execute_cmd/pipes.c ./redirectons/open_redirection_files.c ./redirectons/print_error.c ./rm_single_double_qoute/rm_single_double_qoute.c ./split_by_token/check_cmd_type.c \
./split_by_token/check_dollar_char_arg.c ./split_by_token/check_export_cmd.c ./split_by_token/check_quote_args.c ./split_by_token/check_var_name.c \
./split_by_token/split_args.c ./split_by_token/split_by_token.c ./split_by_token/split_delimiter.c ./split_by_token/split_expand_variable.c \
./split_by_token/split_quote.c ./split_by_token/split_redirects_heredoc_pipe.c ./check_syntax_error/errors.c ./check_syntax_error/ft_check_syntax_error.c \
./history/create_cmd_file.c ./history/history.c ./augment_shell_level.c ./init.c ./input.c ./main.c ./process_cmd.c ./builtins_cmd/builtins_cmd.c \
./builtins_cmd/cd.c ./builtins_cmd/cd_tools.c ./builtins_cmd/echo.c ./builtins_cmd/env.c ./builtins_cmd/exit.c ./builtins_cmd/export.c ./builtins_cmd/pwd.c \
./builtins_cmd/unset.c ./create_cmd/cmd_fds.c ./create_cmd/create_cmd.c ./create_cmd/error_cmd.c ./check_syntax_after_parssing/ft_check_syntax_after_pars.c \
ft_func/ft_close.c ft_func/ft_putstr_fd.c ft_func/ft_open.c env_variable/set_env_vars/init_data.c execute_cmd/execute_cmd_tools.c builtins_cmd/cd_tools3.c builtins_cmd/cd_tools2.c \
herdoc/herdoc_tools2.c

OBJ = ./cpp_map/cpp_map_add.o ./cpp_map/cpp_map_clear.o ./cpp_map/cpp_map_delete.o ./cpp_map/cpp_map_foreach.o ./cpp_map/cpp_map_get.o \
./cpp_map/cpp_map_hash_function.o ./cpp_map/cpp_map_new.o ./cpp_map/cpp_resize.o ./cpp_map/prime_nums.o ./cpp_string/cpp_str_add.o ./cpp_string/cpp_str_delete.o \
./cpp_string/cpp_str_insert.o ./cpp_string/cpp_str_new.o ./cpp_string/cpp_str_resize.o ./herdoc/herdoc_tools.o ./herdoc/herdoc.o\
./cs_list/cs_list_contains.o ./cs_list/cs_list_delete.o ./cs_list/cs_list_insert.o ./cs_list/cs_list_new.o ./cs_list/cs_list_resize.o ./cs_list/ft_memcpy.o \
./cs_list/cs_list_add.o ./ft_func/ft_strjoin.o ./ft_func/ft_strlcat.o ./ft_func/ft_strncmp.o ./ft_func/ft_strnstr.o ./ft_func/ft_substr.o ./ft_func/ft_strrchr.o \
./ft_func/ft_atoi.o ./ft_func/ft_itoa.o ./ft_func/ft_split.o ./ft_func/ft_strchr.o ./ft_func/ft_strchrlen.o ./ft_func/ft_strdup.o \
./ft_func/ft_strlen.o ./ft_func/replace_char.o ./garbage_collector/ft_calloc.o ./garbage_collector/ft_exit.o ./garbage_collector/ft_free.o \
./garbage_collector/ft_save_mem.o ./garbage_collector/mem_list.o ./get/get_next_line.o ./herdoc/create_file_name.o ./herdoc/delete_files.o\
./get/get_next_line_utils.o ./env_variable/get_env_vars/add_env_variable_token.o ./env_variable/get_env_vars/create_key_token.o \
./env_variable/get_env_vars/get_env_variable.o ./env_variable/get_env_vars/get_env_vars_heredoc.o ./env_variable/set_env_vars/set_env_checkes.o \
./env_variable/set_env_vars/set_env_variable.o ./env_variable/env_variable.o ./env_variable/split_var_token.o ./execute_cmd/execute_cmd.o \
./execute_cmd/pipes.o ./redirectons/open_redirection_files.o ./redirectons/print_error.o ./rm_single_double_qoute/rm_single_double_qoute.o ./split_by_token/check_cmd_type.o \
./split_by_token/check_dollar_char_arg.o ./split_by_token/check_export_cmd.o ./split_by_token/check_quote_args.o ./split_by_token/check_var_name.o \
./split_by_token/split_args.o ./split_by_token/split_by_token.o ./split_by_token/split_delimiter.o ./split_by_token/split_expand_variable.o \
./split_by_token/split_quote.o ./split_by_token/split_redirects_heredoc_pipe.o ./check_syntax_error/errors.o ./check_syntax_error/ft_check_syntax_error.o \
./history/create_cmd_file.o ./history/history.o ./augment_shell_level.o ./init.o ./input.o ./main.o ./process_cmd.o ./builtins_cmd/builtins_cmd.o \
./builtins_cmd/cd.o ./builtins_cmd/cd_tools.o ./builtins_cmd/echo.o ./builtins_cmd/env.o ./builtins_cmd/exit.o ./builtins_cmd/export.o ./builtins_cmd/pwd.o \
./builtins_cmd/unset.o ./create_cmd/cmd_fds.o ./create_cmd/create_cmd.o ./create_cmd/error_cmd.o ./check_syntax_after_parssing/ft_check_syntax_after_pars.o \
ft_func/ft_close.o ft_func/ft_putstr_fd.o ft_func/ft_open.o env_variable/set_env_vars/init_data.o execute_cmd/execute_cmd_tools.o builtins_cmd/cd_tools3.o builtins_cmd/cd_tools2.o \
herdoc/herdoc_tools2.o

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -lreadline -o $(NAME)

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY:  all clean fclean re

.SECONDARY: