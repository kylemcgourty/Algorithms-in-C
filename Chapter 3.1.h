//
// Created by Kyle McGourty on 9/19/18.
//

#ifndef ALGORITHMS_CHAPTER_3_1_H
#define ALGORITHMS_CHAPTER_3_1_H

float gpa_calculator(char grades[5][3], int grades_length);

int binary_search_strings(char *key, int keys_length, char string_keys[11][3]);

int search_values(int key);

int put_values(int key, int value, int size);

extern int *unordered_array;

int OrderedSequentialSearchST_Search(char *key);

int OrderedSequentialSearchST_Insert(char *key, int value);

#endif //ALGORITHMS_CHAPTER_3_1_H
