#ifndef _PRINTF_H
#define _PRINTF_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int _putchar(int c);

int print_string(char *str);

int print_spec(char c);

/* _prinf.c module */
int _printf(const char *format, ...);

#endif