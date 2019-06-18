#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__

#include <stdlib.h>
#include <stdbool.h>
#include <memory>
using namespace std;

struct ListNode;
typedef shared_ptr<ListNode> ListNodePtr;

struct ListNode
{
    ListNodePtr next;
    void *value;
};

struct LinkedList
{
    ListNodePtr head;
    size_t len;
    size_t typesize;

    void (*dup)(void *, void *);
    void (*match)(void*,void*);
    void (*free)(void*);
};
typedef shared_ptr<LinkedList> LinkedListPtr;

#define listSetDupMethod(l,m)((l)->dup = (m))
#define listSetFreeMethod(l,m)((l)->free = (m))
#define listSetMatchMethod(l,m)((l)->match= (m))

#define listGetDupMethod(l) ((l)->dup)
#define listGetFree(l)((l)->free)
#define listGetMatchMethod(l) ((l)->match)

LinkedListPtr listCreate();
void listRelease(LinkedListPtr list);
void listEmpty(LinkedListPtr list);
LinkedListPtr listAddNodeHead(LinkedListPtr list, void *value);
LinkedListPtr istAddNodeTail(LinkedListPtr list, void *value);
LinkedListPtr listInsertNode(LinkedListPtr list, ListNodePtr oldNode, void *value, bool after);
void listDelNode(LinkedListPtr list, ListNodePtr node);

ListNodePtr listSearchKey(LinkedListPtr list, void *key);
ListNodePtr listIndex(LinkedListPtr list, long index);
LinkedListPtr listRewind(LinkedListPtr list);

size_t listLength(LinkedListPtr list);

#endif // !__SNGLELIST_H__