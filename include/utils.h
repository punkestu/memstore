#ifndef UTILS__H__
#define UTILS__H__

#include <stddef.h>

enum type
{
    BYTE,
    INT,
    FLOAT,
    STRING,
};

struct node
{
    char *name;
    void *value;
    size_t size;
    enum type t;
    struct node *next;
};

void printnode(struct node *n);

#endif // UTILS__H__