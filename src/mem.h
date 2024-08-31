#ifndef MEM
#define MEM

#define MEM_DEFAULT_SIZE 32

typedef void (*t_destroy_function)();

typedef struct s_mem
{
    int call_stack_size;
    t_destroy_function *call_stack;

} t_mem;

void mem_cleanup();

#endif /* MEM */
