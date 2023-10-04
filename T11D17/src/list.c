#include "list.h"

#include <stdlib.h>

struct node* init(struct door* door) {
    // Кол-во дверей
    // int count = sizeof(door) / sizeof(door[0]);
    // Нулевой элемент / конец списка
    Node* head = NULL;
    // Одна дверь
    struct node* noda = (struct node*)malloc(sizeof(Node));
    noda->data = *door;
    noda->next = head;
    // Если дверей много
    // for (int i = 0; i < count - 1; i++) {
    //     struct node* noda = (struct node*)malloc(sizeof(Node));
    //     noda->data = *door;
    //     noda->next = head;
    //     head = noda;
    // }
    return noda;
}
struct node* add_door(struct node* elem, struct door* door) {
    struct node* noda = (struct node*)malloc(sizeof(Node));
    noda->data = *door;
    elem->next = noda;
    noda->next = elem + 1;
    return noda;
}
struct node* find_door(int door_id, struct node* root) {
    int count = sizeof(root) / sizeof(struct door);
    for (struct node* p = root; p - root < count; p++) {
        if (p->data.id == door_id) {
            return p;
        }
    }
    return NULL;
}
struct node* remove_door(struct node* elem, struct node* root) {
    if (elem != root) {
        (elem - 1)->next = elem + 1;
    } else {
        root = root + 1;
    }
    return root;
    free(elem);
}

void destroy(struct node* root) { free(root); }