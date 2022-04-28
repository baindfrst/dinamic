#include <stdio.h>
#include <stdio.h>
#include "ocher.h"

int main()
{
    ochered* head = NULL;
    char c;
    for (int i = 0; i != 5; i++)
    {
        push(&head, (c = getc(stdin)));
    }
    for (int i = 0; i != 6; i++)
    {
        printf("%c", pop(&head));
    }
    return 0;
}