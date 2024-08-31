#include <stdio.h>
#include "debug.h"
#include "args_parser.h"
#include <stdlib.h>
#include "mem.h"
#include <string.h>

/**
 * Global struc to keep track all alloc ptr. You should create a `_create()`
 * and `_destroy()` function for each type of allocation.
 */
t_mem g_data;

void init()
{
    LOG_TRACE(NULL);
    atexit(mem_cleanup);
    bzero(&g_data, sizeof(g_data));
}

int main(int ac, char **av)
{
    LOG_TRACE("%s started with %d arg(s)", av[0], ac);

    // Init global mem variable
    init();

    start_parsing(ac, av);

    return 0;
}