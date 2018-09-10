#include <stdio.h>
#include <stdlib.h>

#include "chapter1.4.h"
#include "chapter2.1.h"
#include "chapter2.3.h"

int main() {
    printf("Hello, Chapter 2.3!\n");


int toBeSorted[] = {3, 4,2, 5, 3, 2, 3, 4,5 ,1, 1,};


QuickSort_SameKeys(toBeSorted, 0, 10);


for (int i = 0; i< 11; i++){
    printf("The sorted array %d\n", toBeSorted[i]);
}





    return 0;
}