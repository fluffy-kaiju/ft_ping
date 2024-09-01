#ifndef MEM
#define MEM

#include <sys/types.h>

#define MEM_DEFAULT_SIZE 32

typedef void(t_destroy_function)(void);

typedef struct s_mem
{
    ssize_t call_stack_size;
    ssize_t end_pos;

    t_destroy_function **call_stack;

} t_mem;

void init_mem(t_mem *mem);
void mem_push_destroyer(t_destroy_function *func);
void mem_cleanup();

#endif /* MEM */
