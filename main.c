#include <stdio.h>

#include "chapter1.4.h"
#include "chapter2.1.h"

int main() {
    printf("Hello, Chapter 2.1!\n");


    int mixed_array[] = { 5, 7, 3, 9, 1, 0, 2, 6, 7, 11, 1, 44};

    ShellSort(mixed_array, 12);

    for (int i = 0; i < 12; i++)
    {
        printf("the array values %d\n", mixed_array[i]);
    }


    return 0;
}