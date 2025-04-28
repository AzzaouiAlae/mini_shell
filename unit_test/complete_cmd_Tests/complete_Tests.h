#ifndef COMPLETE_TESTS_H
#define COMPLETE_TESTS_H

#include "../Tests.h"


void OthetTests();
void SimpleTests();
void MandatoryTests();
void builtins_complete_Tests();
void execute_cmd_input(char *input);
void assert_env_var(char *input, char *key, char *exp);
void builtins_complete(char *input, t_cmd *exp, int cmds_count);

#endif