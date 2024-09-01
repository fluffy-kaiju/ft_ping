#include <stdio.h>
#include "ft_ping_errors.h"
#include "debug.h"

void start_parsing(int ac, char **av)
{
    if (ac <= 1)
    {
        LOG_ERROR("Only recive %d argument(s)", ac - 1);
        printf(BAD_USAGE_NO_DEST "\n");
    }
}