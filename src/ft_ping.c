#include <stdio.h>
#include "debug.h"
#include "args_parser.h"

int main(int ac, char **av)
{
    LOG_TRACE("%s started", av[0]);

    start_parsing(ac, av);

    return 0;
}