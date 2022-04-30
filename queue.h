#ifndef __LISTS_H__
#define __LISTS_H__

typedef struct node
{
    char elem;
    struct node *next;
} node;

char popQ(node**A); 
int lenQ(node*);
void pushQ (char c, node **A);
void printQ (node * p);
void freeQ(node * p);
int peakQ (node*p, char c);
char take_by_ind(node*, int);
void del_elem_ind(node**, int);
void paste_elem_ind(node**, int, char);

#endif

