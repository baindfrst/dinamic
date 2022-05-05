#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
//A and p are poinyers at the queue
type_of_elem popQ(node**A) // first in queue element
{
    type_of_elem out = (*A)->elem;
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

void pushQ (type_of_elem c, node **A) // add new element
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

void freeQ(node ** p) //delete the whole queue
{
    if(*p)
    {
        *p = (*p)->next;
        freeQ(p);
        free(*p);
    }
}

int peakQ (node* p, type_of_elem c) //возврашает номер элемента С в очереди 
{
    int index = 0;
    while (p != NULL)
    {
        if ((p->elem) == c)
        {
            break;
        }
        p = p->next;
        index++;
    }

    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return index;
    }
}

void copyQ(node** in, node* from)
{
    while (from != NULL)
    {
        pushQ(from->elem, in);
        from = from->next;
    }
}

int emptyQ(node * p) //is the queue empty
{
    if (!p)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int check_copyQ(node*p, node*A) //checking the identity of queues
{
    node* startp = p;
    node* startA = A;
    if (p)
    {
        if ((p->elem) == (A->elem))
        {
            check_copyQ (p->next, A->next);
        }
        else
        {
            return 0;
        }
    }
    p = startp;
    A = startA;
    return 1;
}

node* firstQ(node *A) //return a reference to the first element
{
    if (!A)
    {
        return NULL;
    }
    else
    {
        return A;
    }
}


node* lastQ (node *A) //return a reference to the last element
{
    while (A->next)
    {
        A = A->next;
    }
    return A;
}

void sortQ (node *A) //sort by character codes
{
    node* last = lastQ(A), * first = firstQ(A);
    type_of_elem c;
    while (first != last)
    {
        if (last->elem < first->elem)
        {
            c = last->elem;
            last->elem = first->elem;
            first->elem = c;
        }
        first = first->next;
    }
}