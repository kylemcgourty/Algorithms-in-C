//
// Created by Kyle McGourty on 9/4/18.
//

#include <stdio.h>


//Chapter 2.1

//2.1.1

char answer2_1_1[] = "EASYQUESTION"
                     "A"
                     "AE"
                     "AEE"
                     "AEEI"
                     "AEEIN"
                     "AEEINO"
                     "AEEINOQ"
                     "AEEINOQS"
                     "AEEINOQSS"
                     "AEEINOQSST"
                     "AEEINOQSSTU"
                     "AEEINOQSSTUY";

//2.1.2

char answer2_1_2[] = "For selection sort, there is one exchange for each iteration of the outer loop. Since the outer loop"
                     "must run on average and at most through n iterations, there are n exchanges in both scenarios.";

//2.1.3

int answer2_1_3[] = {8,7,6,5,4,3,2,1};


//2.1.4

char answer2_1_4[] = "EASYQUESTION"
                     "AE"
                     "AES"
                     "AESY"
                     "AEQSY"
                     "AEQSUY"
                     "AEEQSUY"
                     "AEEQSSUY"
                     "AEEQSSTUY"
                     "AEEIQSSTUY"
                     "AEEIOQSSTUY"
                     "AEEINOQSSTUY";

//2.1.5

char answer2_1_5[] = "The two conditions are j > 0 and a[j] < a[j-1]."
                     "An array where the first condition is always false when the loop terminates:";

int first_array[] = {7,6,5,4,3,3,1};

char explanation1[] = "The loop is in reverse order. It always sorts the minimum entry to the beginning of the loop. Upon"
                      "the next iteration, j < 0";

int second_array[] = {1,2,3,4,5,6,7};

char explanation2[] = "The loop is already sorted. Insertion sort's second condition (a[j] < a[j-1] will always be false.";



//2.1.6

char answer2_1_6[] = "Insertion sort runs faster. Selection sort's interior loop runs on average 1/2n times even when the keys"
                      "are identical. Selection sorts interior loop will never proceed under this condition.";

//2.1.7

char answer2_1_7[] = "When running these methods in on an array in reverse order, both inner loops will run a maximum number of times."
                     "If follows that the number of exchanges for selection sort will be proportional to n while the number of "
                     "exchanges for insertion sort will be proportional to (n^2)/2. It follows that selection short should be faster.";

//2.1.8
char answer2_1_8[] = "For a randomly sorted array consisting of three numbers, the array will slowly be sorted into three sections. As"
                     "a new letter (number) is selected, it will need to traverse back 2/3 exchanges, 1/3 exchanges, or 0"
                     "exchanges. The average number of exchanges is 1/3. Thus the runtime is around 1/2 * 1/3 = 1/6(n^2), somewhere "
                     "close to a quadratic runtime.";

//2.1.9

char answer2_1_9[] = "                  E A S Y S H E L L S O R T Q U E S T I O N"
                     "13-sort           T A S Y S H E L L S O R E Q U E S T I O N"
                     "4-sort            E A E E L H I L L N Q O O S S S R S T U Y"
                     "1-sort            A E E H I L L L N O O Q R S S S S T T U Y";

//2.1.10

char answer[] = "Selection will always use a quadratic runtime.";


//2.1.11


int less(int p, int q){
    if (q <= p){
        return 0;
    } else {
        return 1;
    }


}

void exchange(int *a, int p, int q){
    int initial_value = a[p];
    a[p] = a[q];
    a[q] = initial_value;


}


int ShellSort(int *random_array, int length){

    int sequences[10];
    int spacer = 1;
    int count = 0;
    sequences[0] = 1;

    while(spacer < length)
    {
        spacer = spacer * 3 + 1;
        sequences[++count] = spacer;
    }

    while(spacer >= 1){
        for (int i = spacer; i < length; i++)
        {
            for (int j = i; j >=spacer && less(random_array[j], random_array[j-spacer]); j -=spacer)
            {
                exchange(random_array, j, j-spacer);
            }
        }

        spacer = sequences[--count];
    }


}


//2.1.12


int ShellSortPrint(int *random_array, int length){

    int sequences[10];
    int spacer = 1;
    int count = 0;
    sequences[0] = 1;
    int tracker = 0;
    while(spacer < length)
    {
        spacer = spacer * 3 + 1;
        sequences[++count] = spacer;
    }

    while(spacer >= 1){
        for (int i = spacer; i < length; i++)
        {
             ++tracker;
            for (int j = i; j >=spacer && less(random_array[j], random_array[j-spacer]); j -=spacer)
            {
                ++tracker;
                exchange(random_array, j, j-spacer);
            }

        }

        spacer = sequences[--count];
    }

    int compares_constant = tracker / length;
    printf("compares / length %d", compares_constant);

}


//from main

//int mixed_array_100[100];
//int mixed_array_1000[1000];
//int mixed_array_10000[10000];
//
//srand(0);
//
//for (int i = 0; i < 100; i++)
//{
//mixed_array_100[i] = rand();
//}
//
//for (int g = 0; g < 1000; g++)
//{
//mixed_array_1000[g] = rand();
//}
//
//for (int h = 0; h < 10000; h++)
//{
//mixed_array_10000[h] = rand();
//}
//
//ShellSortPrint(mixed_array_100, 100);
//ShellSortPrint(mixed_array_1000, 1000);
//ShellSortPrint(mixed_array_10000, 10000);

// compares to length values: 8, 13, 22
