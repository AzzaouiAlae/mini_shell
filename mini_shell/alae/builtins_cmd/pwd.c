#include "builtins.h"

void pwd(t_cmd *cmd)
{
    char buf[4097];

    ft_bzero(buf, 4097);
    printf("%s\n",getcwd(buf, 4097));
}
