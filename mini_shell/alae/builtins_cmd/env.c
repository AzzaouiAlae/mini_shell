#include "builtins.h"

void	print_env(t_key_value *kvp)
{
	t_cs_list	*value;

	value = kvp->value;
	if (value->type)
		printf("%s=%s\n", kvp->key, (char *)(value->content));
}

void env(t_cmd *cmd)
{
    if (cmd->args && !cmd->args[1]);
        cpp_map_foreach(g_all.custom_env, print_env);
}
