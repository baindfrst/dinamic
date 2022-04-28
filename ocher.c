#include <stdlib.h>
#include <stdio.h>
#include "ocher.h"


void push(ochered **head, char data)
{
    ochered *tmp = (ochered*) malloc(sizeof(ochered));
    tmp->data = data;
    tmp->next = (*head);
    (*head) = tmp;
}

char pop(ochered **head)
{
    ochered* pr = NULL;
    ochered* prev = NULL;
    ochered* tmp = *head;
    char val;
    if (*head == NULL)
    {
        fprintf(stderr, " //err - ochered was empty//");
        exit(-1);
    }
    if (((*head)->next) != NULL)
    {
        while (((*head)->next) != NULL)
        {
            prev = *head;
            (*head) = (*head)->next;
        }
        pr = (*head);
        val = pr->data;
        free(pr);
        prev->next = NULL;
        *head = tmp;
    }
    else
    {
        val = (*head)->data;
        *head = NULL;
    }
    return val;
}