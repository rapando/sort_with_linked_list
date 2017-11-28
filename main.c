#include <stdio.h>

#include "linked_list.h"


int main() {

    printf("Welcome to the sorting Machine\n\n\n");

/*
 * Have several linked lists :
 * One for storing the original list -                  original_list
 * One for storing unsorted list for Insertion Sort -   unsorted_insertion
 * One for storing sorted Insertion Sort -              sorted_insertion
 * One for storing unsorted list for Selection sort -   unsorted_selection
 * One for storing sorted list for Selection Sort -     sorted_selection
 */
    list_t *original_list = list_create();
    list_t *original_list_two = list_create();

    // list_t *unsorted_insertion = list_create();
    // list_t *sorted_insertion = list_create();
    // list_t *unsorted_selection = list_create();
    // list_t *sorted_selection = list_create();

//    Have variables to store the number of inputs expected and also one value at a time

    int qtty;
    int temp;
    int i;

    printf("Please enter the quantity of numbers to be sorted:\n");
    scanf("%d", &qtty);

//    now add data to original linked list
    for (i = 0; i < qtty; i++) {
        printf("Please enter the next number:\n");
        scanf("%d", &temp);
        if (add_node_to_list(original_list, node_create(temp)) == 1) {
//            printf ("Added successfully. New count : %d\n", original_list->count);
        } else {
            printf("unable to add this number\n");
        }

        if (add_node_to_list(original_list_two, node_create(temp)) == 1) {
//            printf ("Added successfully. New count : %d\n", original_list->count);
        } else {
            printf("unable to add this number\n");
        }

    }


    printf ("\nHere are the results of sorting with insertion sort:\n");
    insertion_sort(original_list);
    printf("\nHere are the results of sorting with selection sort:\n");
    insertion_sort(original_list_two);
    // selection_sort(unsorted_selection);

    return 0;

}