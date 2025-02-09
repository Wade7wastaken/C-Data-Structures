#include "string.h"
#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

int compare_ints(const void* a, const void* b) {
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    return arg1 - arg2;
}

int main(void) {
    vector arr = vector_create(5);
    for (int i = 0; i < 100; i++) {
        vector_push(&arr, rand());
    }

    string str1 = vector_to_string(&arr);
    printf("%s\n", string_c(&str1));
    string_drop(&str1);

    qsort(arr.data, arr.size, sizeof(int), compare_ints);

    string str2 = vector_to_string(&arr);
    printf("%s\n", string_c(&str2));
    string_drop(&str2);

    string str3 = string_new();
    for (char c = 33; c <= 126; c++) {
        printf("%s\n", string_c(&str3));
        string_push_char(&str3, c);
    }
    printf("%s\n", string_c(&str3));
    printf("Done\n");
}