//
// Created by Kyle McGourty on 10/9/18.
//

#ifndef ALGORITHMS_CHAPTER_3_4_H
#define ALGORITHMS_CHAPTER_3_4_H

struct Node {
    char key[15];
    int value;
    struct Node *next;
};


int get(struct Node *ST[], char key[15]);

int put(struct Node *ST[], char key[15], int value);

unsigned long hash1(unsigned char *str);

int hash_function(int letter);

int delete_separate_chaining(struct Node *ST[], char key);

void linear_probing_put(char * keys, int * values, char key, int value, int keys_length);

int linear_probe_hash(char key);


#endif //ALGORITHMS_CHAPTER_3_4_H
