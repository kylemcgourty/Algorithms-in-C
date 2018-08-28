//
// Chapter 1.4.
//
#include <limits.h>
#include <stdlib.h>
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
