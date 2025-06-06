#ifndef TESTS_H
# define TESTS_H

# include "Unity-master/src/unity.h"
# include "../mini_shell/mini_shell.h"

typedef struct s_split_tokens_data
{
    char *s;
    char *sep;
    char *special_sep;
    struct s_token	*exp;
    int count;
} t_split_tokens_data;

void pipe_Test();
t_split_tokens_data *data();
void split_tokens_test();
void simple_tests();
char *get_enum_str(int type);
void redirects_Tests();
void builtins_Test();
void Test_syntax_error();
void heredoc_Test();
void mandatory_Tests();
void Test_cpp_map();
void Test_env_vars();
void more_Tests();
void mini_shell_map_Tests();
void set_vars_Tests();
void get_vars_Tests();
void complete_cmd_Tests();
void builtins_Test31();


#endif