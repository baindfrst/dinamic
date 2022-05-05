#include <stdio.h>
#include <stdio.h>
#include "queue.h"

int main()
{
    node* head = NULL;
    node* head2 = NULL;
    pushQ('f', &head);
    pushQ('e', &head);
    pushQ('d', &head);
    pushQ('c', &head);
    pushQ('b', &head);
    pushQ('a', &head);
    printf("queue 'head': ");
    printQ(head);
    printf("\nqueue 'head' length: %d\n", lenQ(head));
    copyQ(&head2, head);
    printf("identity of queues 'head' and 'head2': %d\n", check_copyQ(head, head2));
    sortQ(head2);
    printf("element %c: %d in queue 'head'\n", 'f', peakQ(head, 'f'));
    printf("element %c: %d in queue 'head2'\n", 'f', peakQ(head2, 'f'));
    freeQ(&head2);
    printf("is the new queue 'head2' empty: %d\n", emptyQ(head2));
    popQ(&head);
    printf("queue 'head' when the first is out:");
    printQ(head);
    printf("\n");
    return 0;
}