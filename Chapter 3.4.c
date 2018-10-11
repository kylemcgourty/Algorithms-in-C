//
// Created by Kyle McGourty on 10/9/18.
//

#include "Chapter 3.4.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//3.4.2



unsigned long hash1(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash % 5381;
}


int get(struct Node* ST[], char key[15])
{
    struct Node node = *ST[hash1(key)];

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
    struct Node node = *ST[hash1(key)];
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
    int hash;
    for (letter = 0; letter < 27; letter++){
        hash = (31* (int) letter) % 29;
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


int delete_separate_chaining(struct Node *ST[], char key)
{
    int hashed_key = hash1(key);
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


//3.4.10


int linear_probe_hash(char key)
{
    int position = key - 'A' + 1;
    return (11*position) % 16;

}

void linear_probing_put(char * keys, int * values, char key, int value, int keys_length)
{
    int i =0;
    for (i = linear_probe_hash(key); keys[i] != '\0'; i = (i+1) % 16)
    {
        int *k = (keys + i);
        if (*k == key)
        {
            *(values+i) = value;
            return;
        }
    }
    *(keys+i) = key;
    *(values+i) = value;

}

//char keys[15];
//int values[15];
//
//int keys_length = sizeof(keys)/ sizeof(char);
//
//memset(&keys, '\0', keys_length);
//
//
//linear_probing_put(keys, values,(char *) 'E', 1, keys_length);
//linear_probing_put(keys, values,(char *) 'A', 2, keys_length);
//linear_probing_put(keys, values,(char *) 'S', 3, keys_length);
//linear_probing_put(keys, values,(char *) 'Y', 4, keys_length);
//linear_probing_put(keys, values,(char *) 'Q', 5, keys_length);
//linear_probing_put(keys, values,(char *) 'U', 6, keys_length);
//linear_probing_put(keys, values,(char *) 'T', 7, keys_length);
//linear_probing_put(keys, values,(char *) 'I', 8, keys_length);
//linear_probing_put(keys, values,(char *) 'O', 9, keys_length);
//linear_probing_put(keys, values,(char *) 'N', 10, keys_length);
//
//
//for (int i = 0; i < keys_length; i++)
//{
//printf("the key %c\n", keys[i]);
//}