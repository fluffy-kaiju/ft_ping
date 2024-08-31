#ifndef DEBUG
#define DEBUG

#include "ansi_colors.h"
#define LOG_BUFFER_SIZE 512

#if LOG_ENABLED

int debug_printf_ln(const char *color, const char *fileName, const char *funcName, unsigned int lineNumber, const char *fmt, ...);

#define LOG_TRACE(fmt, ...) debug_printf_ln(ANSI_COLOR_WHITE, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_DEBUG(fmt, ...) debug_printf_ln(ANSI_COLOR_GREEN, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_WARNING(fmt, ...) debug_printf_ln(ANSI_COLOR_YELLOW, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) debug_printf_ln(ANSI_COLOR_RED, __FILE__, __FUNCTION__, __LINE__, fmt, ##__VA_ARGS__)

#else

#define LOG_TRACE(fmt, ...)
#define LOG_DEBUG(fmt, ...)
#define LOG_WARNING(fmt, ...) debug_printf_ln(ANSI_COLOR_YELLOW, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...) debug_printf_ln(ANSI_COLOR_RED, fmt, ##__VA_ARGS__)

#endif

#endif /* DEBUG */
