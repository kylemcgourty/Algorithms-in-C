#include <stdio.h>

#include "chapter1.4.h"

int main() {
    printf("Hello, World!\n");

    int count = 0;
    int integer_list[] = {1,2,-3, 1,5,-6};
    int length = sizeof(integer_list)/ sizeof(int);

    count = ThreeSum(integer_list, length);

    printf("the returned count %d", count);
    return 0;
}