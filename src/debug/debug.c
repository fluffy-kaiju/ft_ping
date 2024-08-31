
#include "debug.h"
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

#ifdef LOG_ENABLED

int debug_printf_ln(const char *color, const char *fileName, const char *funcName, unsigned int lineNumber, const char *fmt, ...)
{
    char parameterBuffer[LOG_BUFFER_SIZE] = {0};
    char outgoingBuffer[LOG_BUFFER_SIZE] = {0};
    va_list params;

    va_start(params, fmt);
    vsnprintf(parameterBuffer, LOG_BUFFER_SIZE, fmt, params);
    va_end(params);

    int ret = snprintf(outgoingBuffer, LOG_BUFFER_SIZE, "%s%s:%u %s(): %s%s", color, fileName, lineNumber, funcName, parameterBuffer, ANSI_COLOR_RESET "\n");
    write(STDERR_FILENO, outgoingBuffer, LOG_BUFFER_SIZE);
    return ret;
}

#else

int printf_ln(const char *color, const char *fmt, ...)
{
    char parameterBuffer[LOG_BUFFER_SIZE] = {0};
    char outgoingBuffer[LOG_BUFFER_SIZE] = {0};
    va_list params;

    va_start(params, fmt);
    vsnprintf(parameterBuffer, LOG_BUFFER_SIZE, fmt, params);
    va_end(params);

    int ret = snprintf(outgoingBuffer, LOG_BUFFER_SIZE, "%s%s%s", color, parameterBuffer, ANSI_COLOR_RESET "\n");
    write(STDERR_FILENO, outgoingBuffer, LOG_BUFFER_SIZE);
    return ret;
}
#endif
