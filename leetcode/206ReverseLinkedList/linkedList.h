#ifndef LINKEDLIST_H
#define LINKEDLIST_H

typedef struct linkedlist LinkedList;
struct linkedlist {
    int value;
    LinkedList *next;
};

#endif
