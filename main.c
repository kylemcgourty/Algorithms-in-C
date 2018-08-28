#include <stdio.h>

#include "chapter1.4.h"

int main() {
    printf("Hello, Chapter 1.4!\n");

    int count = 0;
    int integer_list[] = {1,2,-3,2, 1,5,-6};

    count = FindPairs(integer_list, 7);

    printf("the final count %d", count);

    return 0;
}