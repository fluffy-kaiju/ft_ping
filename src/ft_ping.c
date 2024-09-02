#include <stdio.h>
#include "debug.h"
#include "args_parser.h"
#include <stdlib.h>
#include "mem.h"

#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <string.h>
#include <arpa/inet.h>

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
    struct addrinfo hints, *res, *p;
    char ipstr[INET6_ADDRSTRLEN];

    memset(&hints, 0, sizeof(hints));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;

    getaddrinfo("mc.dreemcloud.net", NULL, &hints, &res);

    for (p = res; p != NULL; p = p->ai_next)
    {
        void *addr;
        char *ipver;

        // get the pointer to the address itself,
        // different fields in IPv4 and IPv6:
        if (p->ai_family == AF_INET)
        { // IPv4
            struct sockaddr_in *ipv4 = (struct sockaddr_in *)p->ai_addr;
            addr = &(ipv4->sin_addr);
            ipver = "IPv4";
        }
        else
        { // IPv6
            struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *)p->ai_addr;
            addr = &(ipv6->sin6_addr);
            ipver = "IPv6";
        }

        // convert the IP to a string and print it:
        inet_ntop(p->ai_family, addr, ipstr, sizeof ipstr);
        printf("  %s: %s\n", ipver, ipstr);
    }

    freeaddrinfo(res);
}

int main(int ac, char **av)
{
    LOG_DEBUG("%s started with %d arg(s)", av[0], ac - 1);

    init();
    test();

    start_parsing(ac, av);

    return 0;
}