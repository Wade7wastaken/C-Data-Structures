#ifndef STRING_H
#define STRING_H

#include <stdlib.h>

typedef struct {
    char* buf;
    size_t len;
    size_t capacity;
} string;

size_t string_len(string* s);

string string_new(void);

// doesn't free str
void string_push(string*, char*);

void string_push_char(string*, char);

char string_get_char(string*, size_t);

char* string_c(string*);

void string_drop(string*);

#endif