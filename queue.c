#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//A and p are poinyers at the queue
char popQ(node**A) // first in queue element
{
    char out = (*A)->elem;
    node* t = (*A);
    *A = (*A)->next;
    free(t);
    return out;
}

int lenQ(node* A)
{
    int out = 0;
    while (A)
    {
        out++;
        A = A->next;
    }
    return out;
}

void pushQ (char c, node **A) // add new element
{
    if (*A == NULL)
    {
        *A = malloc(sizeof(node));
        (*A)->elem = c;
        (*A)->next = NULL;
    }
    else
        pushQ(c, &((*A)->next));
}

void printQ (node * p) //print the whole queue
{
    if (p)
    {
        printf("%c", p->elem);
        printQ(p->next);
    }
}

void freeQ(node * p) //delete the whole queue
{
    if(p)
    {
        freeQ(p->next);
        free(p);
    }
}

int peakQ (node*p, char c) //возврашает номер элемента С в очереди 
{
    int index = 0;
    node* start = p;
    while (p != NULL)
    {
         ++index;
        if ((p->elem) == c )
        {
            break;
        }
        else p = p->next;
    }
    p = start;
    return index;
}

void copyQ(node** in, node* from)
{
    while (from != NULL)
    {
        pushQ(from->elem, in);
        from = from->next;
    }
}