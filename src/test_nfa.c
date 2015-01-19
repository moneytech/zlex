/* test of NFA lexical analyzer and parser */

#include <stdio.h>
#include <malloc.h>
#include "nfa.h"

char *macros[] = {
    "DM 0-7",
    "D [{DM}89]",
    NULL,
};

char *rules[] = {
    "{D}+ return ICON;",
    "({D}+|{D}*\\.{D}+|{D}+\\.{D}*)(e{D}+)? return FCON",
    NULL
};

#define MAXBUF 2048
char **line = rules-1;

char *get_expr(void)
{
    line++;
    return *line;
}

int main(int argc, char *argv[])
{
    /* add macros */
    char **p = macros;
    while (*p != NULL) {
        new_macro(*p);
        p++;
    }

    nfa_t *start = thompson(get_expr);
    print_nfa(start, NFA_GRAPHVIZ);
    /* print_nfa(start, NFA_PLAIN); */

    return 0;
}
