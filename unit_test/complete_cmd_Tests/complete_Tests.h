#ifndef COMPLETE_TESTS_H
#define COMPLETE_TESTS_H

#include "../Tests.h"

void builtins_complete_Tests();
void OthetTests();
void execute_cmd_input(char *input);
void assert_env_var(char *input, char *key, char *exp, int len);
void builtins_complete(char *input, t_cmd *exp, int cmds_count);

#endif