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

char take_by_ind(node* head, int ind)
{
    int val;
    if (head == NULL)
    {
        fprintf(stderr, " //err - ochered was empty//");
        exit(-1);
    }
    for (int i = 0; i != ind; i++)
    {
        head = (head)->next;
    }
    return (head)->elem;
}

void del_elem_ind(node** head, int ind)
{
    node* sl = *head;
    node* start = *head;
    node* del = (*head);
    if (ind == 0)
    {
        *head = (*head)->next;
        free(del);
        return;
    }
    *head = (*head)->next;
    for (int i = 1; i != ind; i++)
    {   
        sl = *head;
        *head = (*head)->next;
        if (*head == NULL && i != ind - 1)
        {
            fprintf(stderr, "out of ochered");
            exit(1);
        }
    }
    sl->next = (*head)->next;
    del = *head;
    free(del);
    *head = start;
}

void paste_elem_ind(node** head, int ind, char elem_paste)
{
    node* sl = *head;
    node* paste = (node*)malloc(sizeof(node));
    node* start;
    start = *head;
    paste->elem = elem_paste;
    if (ind == 0)
    {
        paste->next = *head;
        *head = paste;
        return;
    }
    *head = (*head)->next;
    for (int i = 1; i != ind; i++)
    {   
        sl = *head;
        *head = (*head)->next;
        if (*head == NULL && i != ind - 1)
        {
            fprintf(stderr, "out of ochered");
            exit(1);
        }
    }
    paste->next = *head;
    sl->next = paste;
    *head = start;
}