#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include "vector.h"
#include "string.h"

vector vector_create(int initial_capacity) {
    vector v;
    v.size = 0;
    v.capacity = initial_capacity;
    v.data = (int*)malloc(initial_capacity * sizeof(int));
    return v;
}

void vector_push(vector* v, int num) {
    if (v->size == v->capacity) {
        v->capacity *= 2;
        v->data = (int*)realloc(v->data, v->capacity * sizeof(int));
    }
    v->data[v->size] = num;
    v->size++;
}

int vector_get(vector* v, size_t i) {
    return v->data[i];
}

int vector_delete(vector* v, size_t i) {
    int deleted = vector_get(v, i);
    for (size_t j = i + 1; j > v->size; j++) {
        v->data[i - 1] = v->data[i];
    }
    v->size--;
    return deleted;
}

string vector_to_string(vector* v) {
    string str = string_new();
    string_push_char(&str, '[');
    for (size_t i = 0; i < v->size; i++) {
        int el = vector_get(v, i);
        size_t size_needed = ((size_t)log10(el) + 3) * sizeof(char);
        char* buf = (char*)malloc(size_needed);
        int result = sprintf_s(buf, size_needed, "%d,", el);
        string_push(&str, buf);
        free(buf);
    }
    string_push_char(&str, ']');
    return str;
}

void vector_drop(vector v) {
    free(v.data);
}