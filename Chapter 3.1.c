//
// Created by Kyle McGourty on 9/19/18.
//

#include "Chapter 3.1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


//3.1.1

char grade_keys[11][3] = {"A", "A+", "A-", "B", "B+", "B-", "C", "C+", "C-", "D","F" };

float grade_values[] = {4.00, 4.33, 3.67, 3.00, 3.33, 2.67, 2.00, 2.33, 1.67, 1.00, 0};


float gpa_calculator(char grades[5][3], int grades_length){

        float gpa_accumulator = 0;
        for (int i = 0; i < grades_length; i++){
            int index = binary_search_strings(&grades[i][0], 11, grade_keys);
            printf("The returned index %d\n", index);
            printf("the added gpa %.2f \n", grade_values[index]);
            gpa_accumulator += grade_values[index];
        }

        return gpa_accumulator/grades_length;

}


int binary_search_strings(char *key, int keys_length, char string_keys[11][3]){
    int lo = 0, hi = keys_length;

    while(lo <= hi){
        int mid = lo + (hi -lo)/2;
        printf("the keys and string keys %s %s\n", key, string_keys[mid]);
        int cmp = strcmp(key, string_keys[mid]);
        printf("the comp value %d\n", cmp);
        if (cmp > 0) lo = mid + 1;
        if (cmp < 0) hi = mid -1;
        else return mid;

    }
    return lo;
}


//char grades[5][3] = {"A", "A+", "B+", "A-", "A"};
//
//
//float gpa = gpa_calculator(grades, 5);
//
//printf("the final gpa %.2f\n", gpa);


//3.1.2


int *unordered_array;

int search_values(int key){


    if (unordered_array[key] == 0 )
    {
        return 0;
    }
    else
    {
        return unordered_array[key];
    }

}

int put_values(int key, int value, int size){


    if (key > size)
    {
        int copy_array[size];

        for (int j=0; j< size; j++)
        {
            copy_array[j] = unordered_array[j];
        }
        unordered_array = realloc(unordered_array, sizeof(int)*key*2);

        for (int i = 0; i <= size; i++){
            unordered_array[i] = copy_array[i];
        }


    }

    unordered_array[key] = value;

    return 0;
}


//unordered_array = (int *) malloc(sizeof(int)*100);
//
//put_values(10, 22, 100);
//
//put_values(101, 3, 100);
//
//int searched1 = search_values(10);
//
//int searched2 = search_values(101);
//
//printf("the return searched %d %d\n", searched1, searched2);
//
//free(unordered_array);




//3.1.3

//An ordered linked list symbol table


struct Node {
    char *key;
    int value;
    struct Node *next;
};

struct Node *first;

int OrderedSequentialSearchST_Insert(char *key, int value){

    int create = 0;

    if (first == NULL)
    {
        struct Node *new_node = malloc(sizeof(struct Node));
        new_node->value = value;
        new_node->key = key;
        new_node->next = NULL;
        first = new_node;
    } else {

        struct Node *next_Node = first;
        int comp;
        while((comp = strcmp(next_Node->key, key)) != 0){

            if (next_Node->next == NULL || ((comp > 0) && (strcmp(next_Node->next->key, key) > 0))) {
                create = 1;
                break;
            }

            next_Node = next_Node->next;

        }

       if (create > 0) {
           struct Node *new_node = malloc(sizeof(struct Node));
           new_node->value = value;
           new_node->key = key;

           if (next_Node->next == NULL){
               next_Node->next = new_node;
               new_node->next = NULL;
           } else {
               new_node->next = next_Node->next;
               next_Node->next = new_node;
           }

       }

        if (strcmp(next_Node->key, key) == 0) {
            next_Node->value = value;
        }






    }
    return 0;



}


int OrderedSequentialSearchST_Search(char *key){

    struct Node *next_Node = first;
    int comp;
    while((comp =strcmp(next_Node->key, key)) != 0){

        if (next_Node->next == NULL) {

            return 0;
        }

        next_Node = next_Node->next;

    }

    return next_Node->value;
}


//
//OrderedSequentialSearchST_Insert("A", 11);
//OrderedSequentialSearchST_Insert("G", 22);
//OrderedSequentialSearchST_Insert("L", 7);
//
//int returnedvalue1 =OrderedSequentialSearchST_Search("L");
//int returnedvalue2 = OrderedSequentialSearchST_Search("A");
//
//printf("the returned values %d %d \n", returnedvalue1, returnedvalue2);