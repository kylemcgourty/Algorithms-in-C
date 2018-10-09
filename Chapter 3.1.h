//
// Created by Kyle McGourty on 9/19/18.
//

#ifndef ALGORITHMS_CHAPTER_3_1_H
#define ALGORITHMS_CHAPTER_3_1_H

#include <time.h>

float gpa_calculator(char grades[5][3], int grades_length);

int binary_search_strings(char *key, int keys_length, char string_keys[11][3]);

int search_values(int key);

int put_values(int key, int value, int size);

extern int *unordered_array;

int OrderedSequentialSearchST_Search(char *key);

int OrderedSequentialSearchST_Insert(char *key, int value);


time_t to_seconds(const char *date);

struct TimeNode* createNode(time_t key, int value);

int time_compare(time_t key1, time_t key2);

void placeTimeNodeBefore(time_t key, int value);


void placeNode(time_t key, int value, struct TimeNode* next_TimeNode);

int TimeLLSymbolTable_Insert(char *date, int value);

int TimeLLSymbolTable_Search(char *key);

extern struct TimeNode* time_first;

//void delete_item(char * date);

removeMiddle(struct TimeNode * previous, struct TimeNode *current);

void removeFirst();

time_t *keys();

int size();

#endif //ALGORITHMS_CHAPTER_3_1_H
