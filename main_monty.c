#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"

#define BUFFER_SIZE 1024

globales_t globalvar = {NULL, NULL, NULL};

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

int main(int argc, char **argv)
{
    char *token = NULL;
    size_t line_buf_size = 0;
    int line_number = 0, flag = 0, flag2 = 0;
    ssize_t line_size;
    stack_t *stack = NULL;

    if (argc != 2)
        stderr_usage();
    globalvar.fd = fopen(argv[1], "r");
    if (globalvar.fd == NULL)
        stderr_fopen(argv[1]);
    line_size = my_getline(&globalvar.line_buf, &line_buf_size, globalvar.fd);
    if (globalvar.line_buf[0] == '#')
        line_size = my_getline(&globalvar.line_buf, &line_buf_size, globalvar.fd);
    while (line_size >= 0)
    {
        flag = 0;
        flag2 = 0;
        line_number++;
        token = strtok(globalvar.line_buf, DELIM);
        globalvar.token2 = strtok(NULL, DELIM);
        if (token == NULL)
        {
            flag2 = 1;
            nop(&stack, line_number);
        }
        if (flag2 == 0)
        {
            if (token[0] == '#')
            {
                line_size = my_getline(&globalvar.line_buf,
                                       &line_buf_size, globalvar.fd);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            get_builtin(token, &stack, line_number);
            line_size = my_getline(&globalvar.line_buf, &line_buf_size,
                                   globalvar.fd);
        }
    }
    free_dlistint(stack);
    free(globalvar.line_buf);
    globalvar.line_buf = NULL;
    fclose(globalvar.fd);
    return (EXIT_SUCCESS);
}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
    ssize_t read;

    if (*lineptr == NULL || *n == 0)
    {
        *n = BUFFER_SIZE;
        *lineptr = malloc(*n * sizeof(char));
        if (*lineptr == NULL)
        {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
    }
    if (fgets(*lineptr, *n, stream) == NULL)
    {
        free(*lineptr);
        *lineptr = NULL;
        return -1;
    }
    read = strlen(*lineptr);
    if ((*lineptr)[read - 1] == '\n')
        (*lineptr)[read - 1] = '\0';
    return read;
}
