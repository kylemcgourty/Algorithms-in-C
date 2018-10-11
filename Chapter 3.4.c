//
// Created by Kyle McGourty on 10/9/18.
//

#include "Chapter 3.4.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "math.h"
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



//3.4.12

char answer3_4_12[] = "A, B, C, D, E, F"
                      "Minimum and maximum probes: 11; Order: B C A G D E F";

//3.4.13

char answer3_4_13[] = "A, C";

//3.4.14

char answer3_4_14[] = "B";

//3.4.15
char answer3_4_15[] = "In the worst case, all keys map to the same index, creating one large cluster. The"
                      "number of compares would be proportional to 1/2 n^2";

//3.4.16

char answer3_4_16[] = "The table is half full, with keys filled at random. There are 10^6/100 = 10,000 keys divisible"
                      "by one hundred. The probability that all of these keys are filled is given by (1/2)(10^4)/(10^6),"
                      "which is .005";

//3.4.17


char keys_after_delete[] = "10, 9, - , -, A, H, S, L, - E, ...";

//3.4.19

void keys_seperate_chaining(struct Node * keys, int keys_length)
{
    for (int i = 0; i< keys_length; i++)
    {
        if ((keys + i)->key == NULL) continue;

        struct Node *node = (keys + i);

        while(1){
            printf("key %s", node->key);
            if (node->next == NULL) break;
            node = node->next;
        }
    }
}


void keys_linear_probing(char * keys, int keys_length){
    for (int i=0; i < keys_length; i++)
    {
        if (*(keys+i) != '\0') printf("key %c \n", *(keys+i));
    }
}

//3.4.20


double linear_probing_average_cost(int num_keys, int table_size)
{
    double lower_bound = 1/2*(1+1/(1-num_keys/table_size));
    double upper_bound = 1/2*(1+1/pow((1-num_keys/table_size), 2));

    return (lower_bound + upper_bound)/2;
}


//3.4.23

int bad_hashing(int string_length, char * s){
    int hash = 0;
    for (int i =0; i < string_length; i++ )
    {
        int position = *(s+i) - 'a' + 1;
        hash = (256 * hash + position) % 255;
    }

    return hash;
}

char answer3_4_23[] = "hash for 'abc' = 6; hash for 'bca' = 6; hash for 'cba' = 6";

//int hash1 = bad_hashing(3, "abc");
//int hash2 = bad_hashing(3, "bca");
//int hash3 = bad_hashing(3, "cba");
//
//printf("The hashes %d %d %d \n", hash1, hash2, hash3);





//3.4.24
char answer [] = "Doubles are not considered here. To echo the book: BST use between ~16n and ~64n bytes of memory, where n is the number of nodes; Separate chaining"
                 "uses ~48n + 32m bytes, where n is key-value pairs and m is the size of the array. Linear probing"
                 "uses between ~32 n and ~128 n bytes.";