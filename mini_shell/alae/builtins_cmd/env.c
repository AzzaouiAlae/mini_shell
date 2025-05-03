#include "builtins.h"
#include "../create_cmd/create_cmd.h"

void	print_env(t_key_value *kvp)
{
	t_cs_list	*value;

	value = kvp->value;
	if (value->type)
		printf("%s=%s\n", kvp->key, (char *)(value->content));
}

void env(t_cmd *cmd)
{
	int i;

	i = 0;
	while(cmd->args[i])
		i++;
	if (i > 1)
		ft_exit(0);
    if (cmd->args && !cmd->args[1]);
        cpp_map_foreach(g_all.custom_env, print_env);
}
