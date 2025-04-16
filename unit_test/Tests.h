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


#endif