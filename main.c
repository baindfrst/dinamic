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
    del_elem_ind(&head, 3);
    printf("\n");
    printQ(head);
    printf("\n");
    paste_elem_ind(&head, 5, 'P');
    printQ(head);
    return 0;
}