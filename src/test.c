#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "store.h"
#include "persist.h"

void test(){
    printf("Test\n");
    void* value = malloc(sizeof(float));
    *(float*)value = atof("4.8");
    set("name", value, 1, FLOAT);
    struct node* temp = get("test");

    printf("is temp NULL? %s\n", temp == NULL ? "yes" : "no");
    assert(temp == NULL);

    temp = get("name");
    printf("is temp NULL? %s\n", temp == NULL ? "yes" : "no");
    assert(temp != NULL);

    printf("Printing node\n");
    printnode(temp);

    persist(getheader(), "store.dat");
    setheader(NULL);
    setheader(restore("store.dat"));

    temp = get("test");
    printf("is temp NULL? %s\n", temp == NULL ? "yes" : "no");
    assert(temp == NULL);

    temp = get("name");
    printf("is temp NULL? %s\n", temp == NULL ? "yes" : "no");
    assert(temp != NULL);

    printf("Printing node\n");
    printnode(temp);
}