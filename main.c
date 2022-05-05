#include <stdio.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    node* head = NULL;
    node* new = NULL;
    char c;
    for (int i = 0; i != 6; i++)
    {
        scanf("%c", &c);
        pushQ(c, &head);
    }
    pushQ('l', &head);
    printQ(head);
    printf("\n");
    for (int i = 0; i != lenQ(head) - 1; i++)
    {
        c = popQ(&head);
        printf("%c ", c);
    }
    printf("\n");
    copyQ(&new, head);
    sortQ(new);
    printQ(new);
    printf("was sorted\n");
    if (check_copyQ(head, new))
    {
        printf("ввод был отсортированный\n");
    }
    else
    {
        printf("ввод был не отсортированный\n");
    }
    freeQ(head);
    freeQ(new);
    if (emptyQ(new) && emptyQ(head))
    {
        printf("end fine\n");
    }
    else
    {
        printf("clear data\n");
    }
    return 0;
}