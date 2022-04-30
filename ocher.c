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
    ochered* tmp;
    tmp = *head;
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

void clearn(ochered **head)
{
    ochered* cl;

    while (((*head)->next) != NULL)
    {
        cl = *head;
        *head = (*head)->next;
        free(cl);
    }

    *head = (*head)->next;
}
char take_by_ind(ochered **head, int ind)
{
    ochered* runer;
    ochered* end;
    char val;

    if (*head == NULL)
    {
        fprintf(stderr, " //err - ochered was empty//");
        exit(-1);
    }

    end = *head;

    while ((end->next) != NULL)
    {
        runer = end;
        end = end->next;
    }

    for (int i = 0; i != ind; i++)
    {

        end = runer;
        runer = *head;

        if (end == *head && i != ind - 1)
        {
            fprintf(stderr, "//index not in ochered//");
            exit(-1);
        }

        if (end == *head)
        {
            val = end->data;
            *head = end->next;
            free(end);

            return val;
        }

        while ((runer->next) != end)
        {
            runer = runer->next;
        }
    }
    val = end->data;
    runer->next = end->next;
    free(end);

    return val;
}