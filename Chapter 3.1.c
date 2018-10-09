//
// Created by Kyle McGourty on 9/19/18.
//

#include "Chapter 3.1.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


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


//3.1.4


//A linked list symbol table processing dates"


time_t to_seconds(const char *date)
{
    struct tm storage = {0, 0, 0, 0 ,0 ,0 ,0 ,0 ,0};
    char *p = NULL;
    time_t retval = 0;

    p = (char *)strptime(date, "%d-%b-%Y", &storage);

    if (p == NULL)
    {
        retval=0;
    }
    else
    {
      retval=mktime(&storage);
    }
    return retval;
}



struct TimeNode {
    time_t key;
    int value;
    struct Node *next;
};

struct TimeNode *time_first;

int time_compare(time_t key1, time_t key2){
    return key1 - key2;
}

void placeTimeNodeBefore(time_t key, int value){

    struct TimeNode *new_node = createNode(key, value);

    if (key < time_first->key){
        new_node->next = time_first->next;
        time_first = new_node;
    }


}

struct TimeNode* createNode(time_t key, int value){
    struct TimeNode *new_node = malloc(sizeof(struct TimeNode));
    new_node->value = value;
    new_node->key = key;
    return new_node;
}


void placeNode(time_t key, int value, struct TimeNode* next_TimeNode){

    struct TimeNode *new_node = createNode(key, value);

    if (next_TimeNode->next == NULL){
        next_TimeNode->next = new_node;
        new_node->next = NULL;
    } else {
        new_node->next = next_TimeNode->next;
        next_TimeNode->next = new_node;
    }
}



int TimeLLSymbolTable_Insert(char *date, int value){

    time_t key = to_seconds(date);

    int create = 0;

    if (time_first == NULL)
    {
        struct TimeNode *new_node = createNode(key, value);
        new_node->next = NULL;
        time_first = new_node;

    } else {

        struct TimeNode *next_TimeNode = time_first;
        int comp;
        while((comp = time_compare(next_TimeNode->key, key)) != 0){

            if (comp < 0)
            {
                placeTimeNodeBefore(key, value);
                break;
            }

            if (comp == 0)
            {
                next_TimeNode->value = value;
                break;
            }



            if (next_TimeNode->next == NULL || ((comp > 0) && (time_compare(next_TimeNode->next->key, key) > 0))) {
                create = 1;
                break;
            }

            next_TimeNode = next_TimeNode->next;

        }

        if (create > 0) {

           placeNode(key, value, next_TimeNode);

        }



    }
    return 0;



}


int TimeLLSymbolTable_Search(char *date){

    time_t key = to_seconds(date);

    struct TimeNode *next_TimeNode = time_first;
    int comp;
    while((comp =time_compare(next_TimeNode->key, key)) != 0){

        if (next_TimeNode->next == NULL) {

            return 0;
        }

        next_TimeNode = next_TimeNode->next;

    }

    return next_TimeNode->value;
}
//
//TimeLLSymbolTable_Insert("24-SEP-1986", 11);
//TimeLLSymbolTable_Insert("23-SEP-1988", 15);
//TimeLLSymbolTable_Insert("20-DEC-1982", 22);
//
//
//int val1 = TimeLLSymbolTable_Search("24-SEP-1986");
//int val2 = TimeLLSymbolTable_Search("20-DEC-1982");
//
//
//printf("retrieving val %d %d", val1, val2);




//3.1.5

//Implementing size, keys, delete for SequentialSearchST

//Using my LLSymbol Table from 3.1.4 as an implementation of SequentialSearchST. With no classes, the implementation is verbose.


int size(){
    int count = 1;
    struct TimeNode * node = time_first;

    while(1){
        node = node->next;
        count++;
        if (node->next == NULL) break;

    }

    return count;


}

time_t *keys(){

    static time_t keys_array[2];

    struct TimeNode * node = time_first;
    int index = 0;
    keys_array[index] = node->key;
    if (node->next == NULL) return keys_array;

    while(1){
        node = node->next;
        keys_array[++index] = node->key;
        if (node->next == NULL) break;

    }

    return keys_array;
}

void removeFirst(){

    struct TimeNode *current = time_first;
    time_first = time_first->next;
    current = NULL;
}

removeMiddle(struct TimeNode * previous, struct TimeNode *current){
    struct TimeNode *toBeRemoved = current;
    previous->next = current->next;
    toBeRemoved = NULL;
}

void delete(char * date){

    time_t key = to_seconds(date);

    struct TimeNode * node = time_first;

    if (node->key == key)
    {
        removeFirst();
        return;
    }

    while(1){
        struct TimeNode * previous = node;
        node = node->next;
        if (node->key == key)
        {
            removeMiddle(previous, node);
            break;
        }
        if (node->next == NULL) break;


    }

    return;


}

//TimeLLSymbolTable_Insert("24-SEP-1986", 11);
//TimeLLSymbolTable_Insert("23-SEP-1988", 15);
//TimeLLSymbolTable_Insert("20-DEC-1982", 22);
//
//
//int val1 = TimeLLSymbolTable_Search("24-SEP-1986");
//int val2 = TimeLLSymbolTable_Search("20-DEC-1982");
//
//
//printf("retrieving val %d %d\n", val1, val2);
//
//printf("the size %d\n", size());
//
//printf("The keys\n");
//
//
//time_t *keys_array = keys();
//
//for (int i=0; i < 2; i++){
//printf("each key %ld\n", *(keys_array+i));
//}
//
//delete("24-SEP-1986");
//
//
//time_t *keys_array2 = keys();
//
//for (int i=0; i < 1; i++){
//printf("each remaining key %ld\n", keys_array2[i]);
//}


//3.1.6 TBC


//3.1.7

char answer3_1_7[] = "For a collection of size N, the probability all keys being distinct is 1 - (1/1000)^N ";

//3.1.8 TBC

//3.1.9 TBC

//3.1.10

char answer3_1_10[] = "E A S Y Q U E S T I O N"
                      "0 1 2 3 4 5 6 7 8 9 10 11"
                      ""
                      "SequentialSearchST"
                      "= E0 "
                      "= A1 E0"
                      "= S2 A1 E0"
                      "= Y3 S2 A1 E0"
                      "= Q4 Y3 S2 A1 E0"
                      "= U5 Q4 Y3 S2 A1 E0"
                      "= U5 Q4 Y3 S2 A1 E6"
                      "= U5 Q4 Y3 S7 A1 E6"
                      "= T8 U5 Q4 Y3 S7 A1 E6"
                      "= I9 T8 U5 Q4 Y3 S7 A1 E6"
                      "= O10 I9 T8 U5 Q4 Y3 S7 A1 E6"
                      "= N11 O10 I9 T8 U5 Q4 Y3 S7 A1 E6"
                      "Compares ~ 12*12/2 = 72";

//3.1.11

char answer3_1_11[] = "E A S Y Q U E S T I O N"
                      "0 1 2 3 4 5 6 7 8 9 10 11"
                      ""
                      "Keys[]"
                      "0 1 2 3 4 5 6 7 8 9 10 11"
                      "E"
                      "A E"
                      "A E S"
                      "A E S Y"
                      "A E Q S Y"
                      "A E Q S U Y"
                      "A E Q S U Y"
                      "A E Q S U Y"
                      "A E Q S T U Y"
                      "A E I Q S T U Y"
                      "A E I O Q S T U Y"
                      "A E I N O Q S T U Y"

                      "Values[]"
                      "0 1 2 3  4  5 6 7 8 9 10 11"
                      "1 6 9 11 4 10 7 8 5 3"

                      "A worst case model of binary search ~2n^2 array accesses in the worst case to construct the table.";



//3.1.12 TBC

//3.1.13

char answer3_1_13[] = "Sequential search has a time complexity of n for searches and insertions. Binary search's runtime for search is log n and for search is n."
                      "With the searches far outweighing the inserts, it is appropriate to use binary search in this instance";

//3.1.14

char answer3_1_14[] = "Binary search has a runtime cost of ~2n for inserts in the worst case, while sequential search only has a cost of n. In this case, it is better"
                      "to use the sequential search linked list implementation.";

//3.1.15

char answer3_1_15[] =
        "Case 1: 1000 searches, 1 insert. For an array of size n, the average cost of a search is lg n. The average cost of an insertion is n."
        "Thus the total time in this case is 1* n + 1000 * lg n. The percentage of total time given to insertions is n /( n + 1000 * lg n)"
        "Case 2: 1,000,000 searches, 1,000 inserts. Total time is 1000n + 1,000,000 lg n. Percentage of time given to inserts is 1000n / (1000n + 1,000,000 lg n), which"
        "is equivalent to the answer given in Case 1. "
        "Case 3: 1,000,000,000 searches, 1,000,000 inserts. Percentage of time given to inserts is 1,000,000/(1,000,000 + 1,000,000,000 lg n), which is again equivalent to"
        "Case 1.";

//3.1.16

int binary_search_keys(char *key, int keys_length, char string_keys[11][3]){
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


//void delete_item(char *delete_key, char keys[][10], int keys_array_length, int values[]){
//
//        int index = binary_search_keys(delete_key, keys_array_length, keys);
//
//        int values_index = keys[index];
//        keys[index] = NULL;
//        values[values_index] = NULL;
//
//        return;
//
//}


//3.1.17


char * floor(char * key, char keys[][10], int keys_array_length){
    return keys[binary_search_keys(key, keys_array_length, keys)-1];
}


//3.1.18

char answer3_1_18[] = "The recurrence relation can be solved with C(n) <= C(Floor(n/2)) + 1. "
                      "Let n be one less than a power of 2, such that n = 2^k -1. Then C(n) = C(2^(k-1)-1) + 1;"
                      "Solving the recurrence relation C(n) = k. Solving for k in the relation n = 2^k - 1 leads to"
                      "lg (n +1) = lg (2^k) = k lg 2. lg (n + 1) = k"
                      "Algorithm 3.2 is not in recursive form can easily converted. After each compare, return "
                      "rank(key, lo, mid-1) or rank(key, mid+1, hi)";

//3.1.19


//void FrequencyCounter(){
//    //...when iterating through they keys of the ST,
//
//    //establish a queue
//
//    struct Counter {
//        char * key;
//        int value;
//        int count;
//        struct *Counter next;
//    };
//
//    //establish beginning and end of queue
//    struct *Counter head;
//    struct *Counter tail;
//
//    int count;
//    //iterate through keys
//            // compare counts
//    if ((counte =st.get(word)) > st.get(max)){
//
//        max = word;
//
//        //add new largest count to queue
//        new_count = CreateCounterNode();
//        new_count->key = key;
//        new_count->count = count;
//    }
//}


//3.1.20


char anwer3_1_20[] = "C(n) <= lg (n + 1) <= lg n + 1; The function is monotonic since lg (n) < lg (n+1) for all n >= 1;"
                     "Since lg n is monotonic, lg (n+1) will increase for all values between powers of 2. E.g.,"
                     "lg n increases for 5, 6, 7. During this time, lg(n+1) is not whole number but so it will need 1 more compare to complete its search,"
                     "hence the recurrence will be less than or equal lg n + 1. Since this relation holds for all numbers between powers of two and powers of two,"
                     "the relation is true for all n >= 1.";