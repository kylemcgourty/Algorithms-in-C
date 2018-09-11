#include <stdio.h>
#include <stdlib.h>

#include "chapter1.4.h"
#include "chapter2.1.h"
#include "chapter2.3.h"

int main() {
    printf("Hello, Chapter 2.3!\n");


int toBeSorted[100] ;

int counter = 0;


for (int i = 0; i< 100; i++){
    toBeSorted[i] = 11;
}

    QuickSort_CompareTracker(toBeSorted, 0, 99, &counter);

  printf("the compares %d", counter);




    return 0;


}