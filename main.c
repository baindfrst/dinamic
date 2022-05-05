#include <stdio.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    node* head = NULL;
    pushQ('a', &head);
    pushQ('b', &head);
    pushQ('c', &head);
    pushQ('f', &head);
    pushQ('e', &head);
    pushQ('d', &head);
    printQ(head);
    printf("\n");
    node* new = NULL;
    copyQ(&new, head);
    sortQ(new);
    printQ(new);
    return 0;
}