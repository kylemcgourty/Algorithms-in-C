//
// Created by Kyle McGourty on 9/10/18.
//

#ifndef ALGORITHMS_CHAPTER2_3_H
#define ALGORITHMS_CHAPTER2_3_H

void QuickSort_SameKeys(int *array, int lo, int hi);

int compare(int first, int second);

int partition(int *a, int lo, int hi, int * counter);

void QuickSort_CompareTracker(int *a, int lo, int hi, int *counter);

int is_less(int i, int j, int* counter);

#endif //ALGORITHMS_CHAPTER2_3_H
