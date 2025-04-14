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


t_split_tokens_data *data();
void split_tokens_test();
void simple_tests();

#endif