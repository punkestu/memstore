#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "persist.h"

void persistto(FILE *file, struct node *current)
{
    if (current == NULL)
    {
        return;
    }
    int len = strlen(current->name);
    fwrite(&len, sizeof(int), 1, file);
    fwrite(current->name, sizeof(char), strlen(current->name), file);
    fwrite((char *)&current->t, sizeof(char), 1, file);
    fwrite((long unsigned int *)&current->size, sizeof(long unsigned int), 1, file);
    if (current->t == BYTE)
    {
        fwrite(current->value, sizeof(char), current->size, file);
    }
    else if (current->t == STRING)
    {
        fwrite(current->value, sizeof(char), current->size, file);
    }
    else if (current->t == INT)
    {
        fwrite(current->value, sizeof(int), 1, file);
    }
    else if (current->t == FLOAT)
    {
        fwrite(current->value, sizeof(float), 1, file);
    }
    persistto(file, current->next);
}

void persist(struct node *head, char *location)
{
    FILE *file = fopen(location, "w");
    if (file == NULL)
    {
        perror("fopen");
        exit(1);
    }
    struct node *current = head;
    persistto(file, current);
    fclose(file);
}

struct node *restore(char *location)
{
    FILE *file = fopen(location, "r");
    if (file == NULL)
    {
        fclose(file);
        return NULL;
    }
    struct node *head = NULL;
    struct node *current = NULL;
    int len = 0;
    while (fread(&len, sizeof(int), 1, file) == 1)
    {
        char *name = (char *)malloc(len);
        fread(name, sizeof(char), len, file);
        enum type t = 0;
        fread(&t, sizeof(char), 1, file);
        size_t size = 0;
        fread(&size, sizeof(long unsigned int), 1, file);
        void *value = malloc(size);
        if (t == BYTE)
        {
            fread(value, sizeof(char), size, file);
        }
        else if (t == STRING)
        {
            fread(value, sizeof(char), size, file);
        }
        else if (t == INT)
        {
            fread(value, sizeof(int), size, file);
        }
        else if (t == FLOAT)
        {
            fread(value, sizeof(float), size, file);
        }
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->name = name;
        new_node->value = value;
        new_node->size = size;
        new_node->t = t;
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            current = new_node;
        }
        else
        {
            current->next = new_node;
            current = new_node;
        }
    }
    fclose(file);
    return head;
}