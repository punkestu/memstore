#ifndef STORE__H__
#define STORE__H__

#include <stddef.h>
#include "utils.h"

struct node *setheader(struct node *head);
struct node *getheader();

struct node *set(char *name, void *value, enum type t);
struct node *get(char *name);


#endif // STORE__H__