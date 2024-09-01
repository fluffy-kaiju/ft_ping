#include <stdio.h>
#include "debug.h"
#include "args_parser.h"
#include <stdlib.h>
#include "mem.h"

/**
 * Global struc to keep track all alloc ptr. You should create a `_create()`
 * and `_destroy()` function for each type of allocation.
 */
t_mem g_data;

void init()
{
    LOG_TRACE(NULL);
    init_mem(&g_data);
    atexit(mem_cleanup);
}

void test()
{
    LOG_WARNING("test123");
}

int main(int ac, char **av)
{
    LOG_DEBUG("%s started with %d arg(s)", av[0], ac - 1);

    init();
    LOG_WARNING("%p", test);
    mem_push_destroyer(&test);

    start_parsing(ac, av);

    return 0;
}