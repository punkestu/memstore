#include <stdlib.h>
#include <string.h>
#include "store.h"

struct node *_head = NULL;

struct node *setheader(struct node *head)
{
    free(_head);
    _head = head;
    return _head;
}

struct node *getheader()
{
    return _head;
}

struct node *set(char *name, void *value, enum type t)
{
    struct node *temp = _head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            temp->value = value;
            temp->size = t == STRING ? strlen((char *)value) : 1;
            temp->t = t;
            return temp;
        }
        temp = temp->next;
    }
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->name = name;
    new_node->value = value;
    new_node->size = t == STRING ? strlen((char *)value) : 1;
    new_node->t = t;
    new_node->next = _head;
    _head = new_node;
    return new_node;
}
struct node *get(char *name)
{
    struct node *temp = _head;
    while (temp != NULL)
    {
        if (strcmp(temp->name, name) == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}