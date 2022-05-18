#ifndef SHELL_H
#define SHELL_H

#include "source.h"


void initsh(void);
int  parse_and_execute(struct source_s *src);
void print_prompt1(void);
void print_prompt2(void);

char *read_cmd(void);

/* shell builtin utilities */
int dump(int argc, char **argv);

/* struct for builtin utilities */
struct builtin_s
{
    char *name;    /* utility name */
    int (*func)(int argc, char **argv); /* function to call to execute the utility */
};

struct word_s
{
    char  *data;
    int    len;
    struct word_s *next;
};

struct word_s *make_word(char *str);
void free_all_words(struct word_s *first);

/* the list of builtin utilities */
extern struct builtin_s builtins[];

/* and their count */
extern int builtins_count;
#endif
