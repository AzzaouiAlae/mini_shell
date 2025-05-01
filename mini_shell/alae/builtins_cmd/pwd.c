#include "builtins.h"

void pwd(t_cmd *cmd)
{
    t_cs_list *value;
    value = cpp_map_get(g_all.custom_env, "PWD");
    cpp_map_add(g_all.custom_env, "OLDPWD", value->content);
    
    printf("this command is not implemented yet\n");
}
