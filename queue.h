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
void copyQ(node**, node*);
node* firstQ(node*);
node* lastQ(node*);
void sortQ (node*);
int empty(node*);
int check_copyQ(node* , node* );

#endif

