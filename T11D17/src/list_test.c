#include "list.h"

#include <stdio.h>
#include <stdlib.h>
// struct Door {
//     int number;
//     char color[10];
// };

// struct Node {
//     struct Door data;
//     struct Node* next;
// };

// struct Node* add_door(struct Node* elem, struct Door* door) {
//     struct Node* noda = (struct Node*)malloc(sizeof(struct Node));
//     noda->data = *door;
//     elem->next = noda;
//     noda->next = elem + 1;
//     return noda;
// }

// void print_linked_list(struct Node* head) {
//     struct Node* current = head;
//     while(current != NULL) {
//         printf("Door Number: %d, Status: %d\n", current->data.number, current->data.color);
//         current = current->next;
//     }
// }

int main() {
    // struct Door door1 = {5, 0};
    // struct Door door2 = {2, 0};

    // // Создание и инициализация первого элемента списка
    // struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    // head->data = door1;
    // head->next = NULL;

    // // Добавление нового элемента в список
    // struct Node* newNode = add_door(head, &door2);

    // // Вывод списка
    // print_linked_list(head);

    // // Освобождение памяти
    // free(newNode);
    // free(head);

    return 0;
}