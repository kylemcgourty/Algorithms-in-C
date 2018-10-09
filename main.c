#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//#include "chapter1.4.h"
//#include "chapter2.1.h"
//#include "chapter2.3.h"
//#include "Chapter 3.1.h"
#include "Chapter 3.4.h"
int main() {
    printf("Hello, Chapter 3.4!\n");


    struct Node *sepearate_chainging_ST[5381];

    printf("before loop \n");

    for(int i = 0; i < 5381; i ++){
        sepearate_chainging_ST[i] = (struct Node *) malloc(sizeof(struct Node));
        sepearate_chainging_ST[i]->value = NULL;
        sepearate_chainging_ST[i]->next = NULL;
    }


    printf("before put \n");
    put(sepearate_chainging_ST, "Kyle", 32);
    put(sepearate_chainging_ST, "Rena", 35);
    put(sepearate_chainging_ST, "Nick", 29);
    put(sepearate_chainging_ST, "Alex", 26);

    printf("after put \n");

    int age1 = get(sepearate_chainging_ST, "Kyle");
    int age2 = get(sepearate_chainging_ST, "Alex");
    int age3 = get(sepearate_chainging_ST, "Rena");
    int age4 = get(sepearate_chainging_ST, "Nick");


    printf("the ages, %d %d %d %d \n", age1, age2, age3, age4);
    return 0;


}