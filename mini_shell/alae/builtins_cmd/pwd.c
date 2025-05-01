#include "builtins.h"

void pwd(t_cmd *cmd)
{
    t_cs_list *value;
    value = cpp_map_get(g_all.custom_env, "PWD");
    printf("%s\n",(char *)value->content);
    // cpp_map_add(g_all.custom_env, "OLDPWD", value->content);
}
