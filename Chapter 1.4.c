//
// Chapter 1.4.
//
#include <limits.h>
//1.4.1

char answer[] ="!n / (3! * (n-3)!)";

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


