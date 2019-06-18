#ifndef __SINGLELIST4_H__
#define __SINGLELIST4_H__

#include <stdlib.h>
#include <stdbool.h>

typedef struct ListNode
{
    struct ListNode *next;
    void *value;
}ListNode;

typedef struct LinkedList
{
    ListNode *head;
    size_t len;
    size_t typesize;

    void (*dup)(void*, void*);
    int (*match)(void *, void *);
    void (*free)(void *);
}LinkedList;

LinkedList *listCreate();
void listRelease(LinkedList *list);
void listEmpty(LinkedList *list);

LinkedList *listAddNodeHead(LinkedList *list, void *value);
LinkedList *listAddNodeTail(LinkedList *list, void *value);
LinkedList *listInsertNode(LinkedList *list, ListNode *oldNode, void *value, bool after);
void listDelNode(LinkedList *list, ListNode *node);

ListNode *listSearchKey(LinkedList *list, void *key);
ListNode *listIndex(LinkedList *list, long index);
LinkedList *listRewind(LinkedList *list);

size_t listLength(LinkedList *list);

#endif //!__SINGLELIST4_H__