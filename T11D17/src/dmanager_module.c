#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "door_struct.h"

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

void initialize_doors(struct door* doors);
void bubbleSort(struct door* doors);
void door_set_closed(struct door* doors);
void output(struct door* doors);

int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    bubbleSort(doors);
    door_set_closed(doors);
    output(doors);
    return 0;
}

// Doors initialization function
// ATTENTION!!!
// DO NOT CHANGE!
void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void bubbleSort(struct door* doors) {
    int size = 15;
    // loop to access each array element
    for (int step = 0; step < size - 1; ++step) {
        // check if swapping occurs
        int swapped = 0;

        // loop to compare array elements
        for (int i = 0; i < size - step - 1; ++i) {
            // compare two array elements
            // change > to < to sort in descending order
            if (doors[i].id > doors[i + 1].id) {
                // swapping occurs if elements
                // are not in the intended order
                struct door temp = doors[i];
                doors[i] = doors[i + 1];
                doors[i + 1] = temp;
                swapped = 1;
            }
        }
        if (swapped == 0) {
            break;
        }
    }
}

void door_set_closed(struct door* doors) {
    for (int i = 0; i < 15; i++) {
        doors[i].status = 0;
    }
}

void output(struct door* doors) {
    for (int i = 0; i < 15; i++) {
        printf("%d, %d", doors[i].id, doors[i].status);
        if (i < 14) printf("\n");
    }
}