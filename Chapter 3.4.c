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

    if (node.value == NULL)
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


//3.4.4

int hash_function(int letter){

    for (letter = 0; letter < 27; letter++){
        int hash = (31* (int) letter) % 29;
        printf("the hash, %d \n", hash);

    }
    return hash;
}


//3.4.5

char answer3_4_5[] = "An implementation of hash code enables an object to have a unique representation. Returning a prime"
                "number as a hashcode helps ensure that it maps to a unique position for all m";

//3.4.6

char answer3_4_6[] = "With modular hashing, m is a prime number to better disperse the modular results. For a value of m > 2,"
                "integers that differ by a bit will either differ by 1 or some power of 2. Thus, for any prime m > 2,"
                "these differences will manifest when taking the modulo of the integer.";

//3.4.7

char answer3_4_7[] = "When a is a arbitray fixed prime, it has the effect converting the digit to a base-a number."
                     "The use of a non-prime m would still leave vulnerabilities however, e.g. the case where"
                     "k is a multiple of m. Thus, it would be prudent to continue using a prime for m.";


//3.4.9


int delete(struct Node *ST[], char key)
{
    int hashed_key = hash(key)
    struct Node* node = ST[hashed_key];

    if (node->key == key) ST[hashed_key] = node->next;
    else
    {
        while(1){
            struct Node * current_node = node;
            if (current_node->next == NULL) break;
            struct Node * node = node->next;

            if (node->key == key)
            {
                current_node->next = node-> next;
                break;

            }

        }
    }

    return 0;
}


/