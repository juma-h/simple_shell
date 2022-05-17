#include <errno.h>
#include "shell.h"
#include "source.h"


/* unget _char - function returns  the last character from input 
 * Returns - void 
*/

void unget_char(struct source_s *src)
{
    if(src->curpos < 0)
    {
        return;
    }

    src->curpos--;
}

/*gets next character and returns*/

char next_char(struct source_s *src)
{
    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }

    char c1 = 0;
    if(src->curpos == INIT_SRC_POS)
    {
        src->curpos  = -1;
    }
    else
    {
        c1 = src->buffer[src->curpos];
    }

    if(++src->curpos >= src->bufsize)
    {
        src->curpos = src->bufsize;
        return EOF;
    }

    return src->buffer[src->curpos];
}

/* gets next char but dooesnt return */

char peek_char(struct source_s *src)
{
    if(!src || !src->buffer)
    {
        errno = ENODATA;
        return ERRCHAR;
    }

    long pos = src->curpos;

    if(pos == INIT_SRC_POS)
    {
        pos++;
    }
    pos++;

    if(pos >= src->bufsize)
    {
        return EOF;
    }

    return src->buffer[pos];
}

/*functions to skip whitespace*/

void skip_white_spaces(struct source_s *src)
{
    char c;

    if(!src || !src->buffer)
    {
        return;
    }

    while(((c = peek_char(src)) != EOF) && (c == ' ' || c == 
 '\t'))
    {
        next_char(src);
    }
}