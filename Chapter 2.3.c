//
// Created by Kyle McGourty on 9/10/18.
//

#include <stdio.h>
#include "chapter2.1.h"
#include "chapter2.3.h"

char answer2_3_1[] = "E A S Y Q U E S T I O N"
                     "E A E Y Q U S S T I O N"
                     "E A E U Q Y S S T I O N";


char answer2_3_2[] = "E A S Y Q U E S T I O N"
                     "E A E Y Q U S S T I O N"
                     "E A E U Q Y S S T I O N"
//partition(0,2)
                     "A E E"
//j = 1, sort (a, 0, 1-1), return
//sort( 3, 11)
//partition(3, 11)
                     "A E E U Q Y S S T I O N"
                     "A E E U N Y S S T I O Q"
                     "A E E U N O S S T I Y Q"
                     "A E E S N O I U T S Y Q"
//j = 7
//sort( 3, 7)
                     "! ! ! S N O I U ! ! ! !"
                     "A E E U N O I S T S Y Q"
//j = 7
// sort(3, 6)
                     "A E E I N O U S T S Y Q"
//j = 6
// sort(3,5)
                     "A E E I N O U S T S Y Q";
//j = 3
// sort (3 ,2) return
// sort(6,6) return
// sort (8,7) return
//And on...TBC


char answer2_3_3[] = "When encountered, the largest item of an array of length n is exchanged once until"
                     "it becomes the value of v on the on the next iteration of partition. At that point, it is"
                     "only exchanged 1 more time as it finds its place at the end of the array. Thus, it is exchanged"
                     "at most two times";

char answer2_3_4[] = "Worst case runtime of QuickSort exists when the array is already sorted, the array is sorted in"
                     "reverse order or all elements are the same";

                    int ordered[] = {1, 2, 3, 4, 5, 6, 7, 8, 9 ,10};

                    int reverse_ordered[] = {10, 9 , 8, 7, 6, 5, 4, 3, 2, 1};

                    char explanation[] = "In both cases, QS's partition runs through the entire array 1-2 times and only exchanges"
                                         "one element per call to partitition. This leads to a quadratic run time";

                    int same_keys[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

                    char same_key_explanation[] = "In this case, QS engages in a maximum number of exchanges while running the length"
                                                "of the array.";

//2.3.5

void QuickSort_SameKeys(int *array, int lo, int hi){
    if (hi <= lo) return;
    int less_than = lo, index = lo + 1, greater_than = hi;

    int partition_key = array[lo];

    while(index <= greater_than)
    {
        int compared = compare(array[index], partition_key);
        if (compared < 0) exchange(array, less_than++, index++);
        else if (compared > 0) exchange(array, index, greater_than--);
        else index++;
    }

    QuickSort_SameKeys(array, lo, less_than -1);
    QuickSort_SameKeys(array, greater_than + 1, hi);
}

int compare(int first, int second){
    if (first < second)
    {
        return -1;
    } else if (first == second)
    {
        return 0;
    } else
    {
        return 1;
    }

}

