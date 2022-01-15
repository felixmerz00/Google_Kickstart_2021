#include <stdio.h>
#include <stdlib.h>

/*Sample input:
2
5 1
ABCAA
4 2
ABAA*/

/*Sample output:
Case #1: 0
Case #2: 1*/

int calculate_goodness(int length, char s[]);
int min_num_of_operations(int length, int goodness_goal, char s[]);

void main()
{
    int number_of_tests;
    scanf("%d", &number_of_tests);
    for(int i = 0; i < number_of_tests; i++){
        int length, goodness_goal, num_operations;
        char s[100];
        scanf("%d", &length);
        scanf("%d", &goodness_goal);
        scanf("%s", s);
        num_operations = min_num_of_operations(length, goodness_goal, s);
        printf("Case #%d: %d\n", i+1, num_operations);
    }
}

/*Returns the minimal number of operations needed to achieve desired goodness level.*/
int min_num_of_operations(int length, int goodness_goal, char s[])
{
    int current_goodness = calculate_goodness(length, s);
    if(goodness_goal == current_goodness){
        return 0;
    }
    else{
        return abs(current_goodness - goodness_goal);
    }
}

/*Calculates the goodness of the string s.*/
int calculate_goodness(int length, char s[])
{
    int last_element = length - 1;
    int goodness = 0;
    /*Iteration through the first half of the elements.
    If length%2==1 then the element in the middle shouldn't be evaluated, thats why "SMALLER THAN length/2" is used*/
    for(int i = 0; i < length/2; i++){
        char c = s[i];
        char d = s[last_element - (i+1) + 1];
        if(s[i] != s[last_element - (i+1) + 1]){
            goodness++;
        }
    }
    return goodness;
}
