//
// Chapter 1.4.
//
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
//1.4.1

char answer1_4_1[] ="!n / (3! * (n-3)!)";

//1.4.2
/* unoptimized version */

int OverFlowChecker(int a, int b, int c){
    if ((b > 0 && c > 0 && a > INT_MAX - b - c) || (b < 0 && c < 0 && a < INT_MIN - b - c))
    {
        return 1;
    }
    else
    {
        return 0;
    }

}


int ThreeSum(int integer_list[], int length) {

    int count = 0;


    for (int i = 0; i < length; i++)
        for(int j = 1 + i; j < length; j++)
            for (int k = j+1; k < length; k++)
                /* check for overflow */
                if (OverFlowChecker(integer_list[i], integer_list[j], integer_list[k]))
                {
                    continue;
                }
                else
                {
                    if (integer_list[i] + integer_list[j]+ integer_list[k] == 0)
                    {
                        ++count;
                    }

                }
    return count;
}


//1.4.3 Pass

//1.4.4 Pass

//1.4.5

char a1_4_5[]  = "n";
char b1_4_5[] = "1/n";
char c1_4_5[] =  "1/n";
char d1_4_5[] = "n^3";
char e1_4_5[] = "1/lg n";
char f1_4_5[] = "2";
char g1_4_5[] = "0";


//1.4.6
char a1_4_6[] = "linear";
char b1_4_6[] = "linear";
char c1_4_6[] = "linearithmic";

//1.4.7
char answer1_4_7[] = "There are three array acccesses per iteration of the inmost loop. The inner loops proceed from starting points i + 1 "
                "and j + 1. The top loops runs length N. The interior loops run from i+1 and j+1 to N. The total costs are "
                "N * Summation ( N - k) * Summation (N - l) ";

//1.4.8


int CompareTwoInts( const void * a, const void * b){
    return ( *(int *) a - *(int *) b);
}

int FindPairs(int input_array[], int length) {
    int count = 0;

    qsort(input_array, length, sizeof(int), CompareTwoInts);

    for (int i = 0; i< length; i++){
        if (input_array[i] == input_array[i+1])
        {
            count++;
        }

    }

    return count;
}

//1.4.9

char answer1_4_9 [] = "Doubling factor is 2^b. Runtime for size n problems is t. Running time of program "
                      "computed by running_time(size_factor) { 2^b * t * size_factor}, where size_factor is integer multiplier"
                      "counting times n0 has been doubled";

//1.4.10

int BinarySearch_ToLowestIndex(int values_to_search[], int list_length, int key){

    int high = list_length - 1;
    int low = 0;
    int mid = high/2;

    while(low < high){
        if (key < values_to_search[mid]) high = mid - 1;
        if (key > values_to_search[mid]) low = mid + 1;
        if (key == values_to_search[mid]) {
            while(key == values_to_search[--mid]){}
            return ++mid;
        }

        mid = low + (high-low)/2;


    }

    return 0;

}


//1.4.11

//ignoring worst case log n constraint

int BinarySearch_FindAllOccurences(int values_to_search[], int low, int high, int key){

    int mid = low + (high-low)/2;

    while(low < high){
        if (key < values_to_search[mid]) high = mid - 1;
        if (key > values_to_search[mid]) low = mid + 1;
        if (key == values_to_search[mid]) {
            int searchdown = mid, searchup = mid;
            while(key == values_to_search[--searchdown]){}
            while(key == values_to_search[++searchup]){}

            return searchup - searchdown - 1;
        }

        mid = low + (high-low)/2;


    }

    return 0;

}

//1.4.12


int FindMutualOccurences(int first_array[], int second_array[], int first_length, int second_length){
    int m =0, n= 0;

    qsort(first_array, first_length, sizeof(int), CompareTwoInts);
    qsort(second_array, second_length, sizeof(int), CompareTwoInts);

    int first_value = first_array[m], second_value = second_array[n];
    while(m != first_length && n != second_length){
        if (first_value == second_value)
        {
            printf("the mutual value! %d\n", first_value);
            first_value = first_array[++m];
            second_value = second_array[++n];
        } else if (first_value < second_value){
            first_value = first_array[++m];
        } else {
            second_value = second_array[++n];
        }


    }


}

//1.4.13

char answer1_14_13[] = "Accumulator: 2 instance variables; one int one double. 4 bytes + 8 bytes + 16 bytes overhead"
                       "Transaction: 3 instance variables?  String = 56 + 2n bytes in Java, date 12 bytes for instance variables + 16 bytes over head, "
                       "plus padding to 32 bytes, one double at 8 bytes + 16 bytes overhead"
                       "FixedCapacityStackOfStrings == 16 bytes overhead for object; Array of strings: 24 bytes overhead + m(56 + 2n) for each string?"
                       "Integer n has 4 bytes; Point2D: 16 bytes overhead + 2 doubles, 8 bytes each; Interval1D: 2 double,"
                       " 8 bytes each, 16 bytes overhead; Interval2D: 2 Iterval1Ds, 2 doubles each, 8* 4 = 32 bytes total + 16 bytes overhead";

