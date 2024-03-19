#ifndef PERSIST__H___
#define PERSIST__H___

#include "utils.h"

void persist(struct node *head, char *location);
struct node *restore(char *location);

#endif // PERSIST__H___