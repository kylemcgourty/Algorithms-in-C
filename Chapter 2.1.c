//
// Created by Kyle McGourty on 9/4/18.
//

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

char answer_2_1_6[] = "Insertion sort runs faster. Selection sort's interior loop runs on average 1/2n times even when the keys"
                      "are identical. Selection sorts interior loop will never proceed under this condition.";