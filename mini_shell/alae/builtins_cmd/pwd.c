#include "builtins.h"

void pwd(t_cmd *cmd)
{
    char buf[4097];
    char *cwd;

    ft_bzero(buf, 4097);
    cwd = getcwd(buf, 4097);
    if (!cwd)
    {
        printf("%s\n", get_from_env("PWD")->content);
        return;
    }
    printf("%s\n", cwd);
}
