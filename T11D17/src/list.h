#ifndef STRUCT_DOOR_H
#define STRUCT_DOOR_H

typedef struct door {
    int id;
    int status;
} Door;

typedef struct node {
    Door data;
    struct node* next;
} Node;

struct node* init(struct door* door);
struct node* find_door(int door_id, struct node* root);
struct node* find_door(int door_id, struct node* root);
struct node* remove_door(struct node* elem, struct node* root);

#endif