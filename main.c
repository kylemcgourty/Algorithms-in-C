#include <stdio.h>

#include "chapter1.4.h"
#include "chapter2.1.h"

int main() {
    printf("Hello, Chapter 1.4!\n");

    int index = 0;
    int integer_list[] = {2, 5, 2, 31, 22, 22, 27, 29};
    int integer_list2[] = {2, 22 ,3 ,22, 27, 30, 31, 5};

   FindMutualOccurences(integer_list, integer_list2, 8, 8);

    return 0;
}