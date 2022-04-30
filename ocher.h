#ifndef __stack__h__
#define __stack__h__

typedef struct ochered
{
    char data;
    struct ochered* next;
} ochered;

void push(ochered**, char);
char pop(ochered**);
void clearn(ochered**);
char take_by_ind(ochered**, int);
#endif