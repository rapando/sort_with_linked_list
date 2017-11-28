#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} node_t;

typedef  struct list {
    int count;
    struct node *first;
} list_t;

int array_size;

// List functions
list_t *list_create () {
    list_t *list = malloc(sizeof(list_t));
    list->count = 0;
    list->first = NULL;
    return list;
}

list_t *list_destroy (list_t *list) {
    list = NULL;
    return list;
}

void list_clear (list_t *list) {
    list->count = 0;
    list->first = NULL;
}

int list_count (list_t *list) {
    return list->count;
}

void print_list (list_t *list) {
    node_t *node = malloc(sizeof(node_t));
    node = list->first;

    while (node != NULL) {
        printf ("%d ", node->value);
        node = node->next;
    }
}

int *linked_list_to_list (list_t *list) {
    int size = list->count;
    int *arr = malloc(sizeof(int) * size);
    int counter = 0;
    node_t *node = malloc(sizeof(node_t));
    node = list->first;

    while (node != NULL) {
        arr[counter] = node->value;
        node = node->next;
        counter++;
    }

    return arr;
}




// Node functions
node_t *node_create (int value) {
    node_t *node = malloc(sizeof(node_t));
    node->value = value;
    node->next = NULL;
}




node_t *list_first (list_t *list) {
    return list->first;
}

int add_node_to_list (list_t *list, node_t *node) {
    if (list->count == 0){
        list->first = node;
        list->count += 1;
        return 1;
    }
    else {
        node_t *current_node = malloc(sizeof (node_t));
        current_node = list_first(list);

        if (list->count == 1) {
            current_node->next = node;
            list->count += 1;
            return 1;
        }
        else {
            while (current_node->next != NULL) {
                current_node = current_node->next;
            }

            current_node->next = malloc(sizeof(node_t));
            current_node->next = node;
            list->count += 1;
            return 1;
        }
    }

}

list_t *list_to_linked_list (int *list, int size) {
    list_t *linked = malloc(sizeof(list_t));
    int i, x;
    for (i = 0; i < size; i++) {
        if (add_node_to_list(linked, node_create(list[i])) == 1) {

        }
    }

    return linked;
}

int pop (list_t *list) {
    int val;

    if (list->count == 0) {
        return -1;
    }
    else if (list->count == 1) {
        val = list->first->value;
        list->first = NULL;
        list->count = 0;
        return val;
    }
    else {
        node_t *first = malloc(sizeof(node_t));
        node_t *second = malloc(sizeof(node_t));

        first = list->first;
        second = list->first->next;

        list->count -= 1;
        list->first = second;

        return first->value;
    }
}



//Sorting functions


int *insertion_sort_implementation (int *list, int size) {
    int i, k, j, d, t;
    int *arr = malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        arr[i] = list[i];
    }

    for (i = 1; i <= size - 1; i++) {
        d = i;
        while (d > 0 && arr[d] < arr[d-1]) {
            t = arr[d];
            arr[d] = arr[d-1];
            arr[d-1] = t;
            d--;
        }
    }


    return arr;
}

void insertion_sort (list_t *unsorted) {
    int *arr = malloc(sizeof(int) * unsorted->count);
    list_t *sorted = malloc(sizeof(list_t));

    int x, i;
    i = 0;
    array_size = 0;
    printf ("U : [");
    print_list(unsorted);
    printf("]\n");

    x = pop(unsorted);

    while (x != -1) {
        if (array_size != 0) {
            printf ("U : [");
            print_list(unsorted);
            printf("]\n");
        }


        arr[array_size] = x;
        arr = insertion_sort_implementation(arr, array_size+1);

        sorted = list_to_linked_list(arr, array_size+1);

        printf("S : [");
        print_list(sorted);
        printf("]\n\n");

        x = pop(unsorted);
        array_size += 1;
    }

}


/*
 int indexMin, i, j;
    for (i = 0; i < c - 1; i++) {
        indexMin = i;
        for(j = i+1;j<c;j++) {
            if(arr[j] < arr[indexMin]) {
                indexMin = j;
            }
        }

        if(indexMin != i) {
//            printf("Items swapped: [ %d, %d ]\n" , arr[i], arr[indexMin]);

            // swap the numbers
            int temp = arr[indexMin];
            arr[indexMin] = arr[i];
            arr[i] = temp;
        }
//        display(arr, c);

    }
    */


int *selection_sort_implementation (int *list, int size) {
    int i, k, j, d, t;
    int indexMin;
    int *arr = malloc(sizeof(int) * size);

    for (i = 0; i < size; i++) {
        arr[i] = list[i];
    }

    indexMin = i;
    for (j = i+1; j < size; j++) {
        if (arr[j] < arr[indexMin]) {
            indexMin = j;
        }
    }

    if (indexMin != i) {
        int temp = arr[indexMin];
        arr[indexMin] = arr[i];
        arr[i] = temp;
    }

    return arr;
}

void selection_sort (list_t *unsorted) {
    int *arr = malloc(sizeof(int) * unsorted->count);
    list_t *sorted = malloc(sizeof(list_t));

    int x, i;
    i = 0;
    array_size = 0;
    printf ("U : [");
    print_list(unsorted);
    printf("]\n");

    x = pop(unsorted);

    while (x != -1) {
        if (array_size != 0) {
            printf ("U : [");
            print_list(unsorted);
            printf("]\n");
        }


        arr[array_size] = x;
        arr = selection_sort_implementation(arr, array_size+1);

        sorted = list_to_linked_list(arr, array_size+1);

        printf("S : [");
        print_list(sorted);
        printf("]\n\n");

        x = pop(unsorted);
        array_size += 1;
    }

}

