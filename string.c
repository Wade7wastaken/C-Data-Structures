#include "string.h"
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

size_t string_len(string* s) {
    return s->len;
}

string string_new(void) {
    string s;
    s.buf = malloc(0);
    s.len = 0;
    s.capacity = 0;
    return s;
}

size_t growth_factor(size_t cur) {
    if (cur == 0) {
        return 1;
    }
    else {
        return cur * 2;
    }
}

// makes sure there are at least amount uninitialized chars
// caller needs to fill them
void grow(string* s, size_t amount) {
    if (s->len + amount > s->capacity) {
        while (s->len + amount > s->capacity) {
            s->capacity = growth_factor(s->capacity);
        }
        s->buf = (char*)realloc(s->buf, s->capacity * sizeof(char));
    }
}

void string_push_char(string* s, char c) {
    grow(s, 1);
    s->buf[s->len] = c;
    s->len++;
}

void string_push(string* s, char* str) {
    size_t in_len = strlen(str);
    grow(s, in_len);
    for (size_t i = 0; i < in_len; i++) {
        s->buf[i + s->len] = str[i];
    }
    s->len += in_len;
}

char string_get_char(string* s, size_t i) {
    return s->buf[i];
}

char* string_c(string* s) {
    grow(s, 1);
    s->buf[s->len] = 0;
    return s->buf;
}

void string_drop(string* s) {
    free(s->buf);
}