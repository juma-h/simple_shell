#include <stdio.h>
#include "shell.h"

/**
 * print_prompt - prints $ or > for prompt
 * Return: void
 */

void print_prompt1(void)
{
    fprintf(stderr, "$ ");
}

void print_prompt2(void)
{
    fprintf(stderr, "> ");
}