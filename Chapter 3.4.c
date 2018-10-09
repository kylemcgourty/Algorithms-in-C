//
// Created by Kyle McGourty on 10/9/18.
//

#include "Chapter 3.4.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//3.4.2



unsigned long hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 5381;
}


int get(struct Node* ST[], char key[15])
{
    struct Node node = *ST[hash(key)];

    if (node.value = NULL)
    {
        return NULL;
    }
    while(1){

        if (node.key == key) {
            return node.value;
        }
        if (node.next == NULL) {
            break;
        }else {
            node = *node.next;
        }

    }

    return NULL;
}

int put(struct Node* ST[], char key[15], int value)
{
    struct Node node = *ST[hash(key)];
    while(1){

        if (node.key == key){
            node.value = value;
            return 0;
        }
        if (node.next == NULL) {
            break;
        }else {
            node = *node.next;
        }

    }

    strcpy(node.key,key);
    node.value = value;
    return 0;

}
