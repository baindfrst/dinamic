#include <stdio.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    node* head = NULL;
    pushQ('a', &head);
    pushQ('b', &head);
    pushQ('c', &head);
    pushQ('d', &head);
    pushQ('e', &head);
    pushQ('f', &head);
    printQ(head);
    printf("\n");
    node* new = NULL;
    copyQ(&new, head);
    printQ(new);
    return 0;
}