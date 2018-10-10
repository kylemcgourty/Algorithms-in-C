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

unsigned long hash(unsigned char *str);

int hash_function(int letter);


#endif //ALGORITHMS_CHAPTER_3_4_H
