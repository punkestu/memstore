#include <stdio.h>
#include "utils.h"

void printnode(struct node *n)
{
    if (n == NULL)
    {
        printf("Node not found\n");
        return;
    }

    if (n->t == BYTE)
    {
        printf("%c\n", *(char *)n->value);
    }
    else if (n->t == INT)
    {
        printf("%d\n", *(int *)n->value);
    }
    else if (n->t == FLOAT)
    {
        printf("%f\n", *(float *)n->value);
    }
    else if (n->t == STRING)
    {
        printf("%s\n", (char *)n->value);
    }
    else
    {
        printf("Unknown type\n");
    }
}