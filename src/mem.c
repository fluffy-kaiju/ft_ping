#include "mem.h"
#include "debug.h"
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
extern t_mem g_data;

void *mem_resize(void)
{

    const int new_size = g_data.call_stack_size ? g_data.call_stack_size * 2 : MEM_DEFAULT_SIZE;

    LOG_DEBUG("Try to resize mem call stack from %d to %d", g_data.call_stack_size, new_size);

#if LOG_ENABLED
    {

        struct rlimit rlimit_as, rlimit_data;
        if (getrlimit(RLIMIT_AS, &rlimit_as) == -1)
        {
            LOG_ERROR("getrlimit failed to get RLIMIT_AS");
        }
        else
        {
            LOG_TRACE("RLIMITS_AS:    cru: %d max: %d", rlimit_as.rlim_cur, rlimit_as.rlim_max);
        }

        if (getrlimit(RLIMIT_DATA, &rlimit_data) == -1)
        {
            LOG_ERROR("getrlimit failed to get RLIMIT_DATA");
        }
        else
        {
            LOG_TRACE("RLIMITS_DATA:  cru: %d max: %d", rlimit_data.rlim_cur, rlimit_data.rlim_max);
        }
    }
#endif

    g_data.call_stack = reallocarray(&g_data.call_stack, sizeof(t_destroy_function), new_size);

    if (g_data.call_stack == NULL)
    {
        LOG_ERROR("Failed to resize mem call stack from %d to %d!!", g_data.call_stack_size, new_size);
        return g_data.call_stack;
    }

    g_data.call_stack_size = new_size;
    LOG_DEBUG("Call stack new size is %d", g_data.call_stack_size);

    return g_data.call_stack;
}

void mem_push_destroyer(t_destroy_function *func)
{
    if ((g_data.call_stack_size + 1) > g_data.call_stack_size)
    {
        if (mem_resize() == NULL)
        {
            exit(-1);
        }
    }
}

void mem_cleanup(void)
{
}