#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
#include "string.h"

typedef struct {
    int* data;
    size_t size;
    size_t capacity;
} vector;

vector vector_create(int initial_capacity);

void vector_push(vector* r, int num);

int vector_get(vector* r, size_t i);

void vector_drop(vector v);

string vector_to_string(vector* v);

#endif