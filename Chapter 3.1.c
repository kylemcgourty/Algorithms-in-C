//
// Created by Kyle McGourty on 9/19/18.
//

#include "Chapter 3.1.h"
#include <stdio.h>
#include <string.h>


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
