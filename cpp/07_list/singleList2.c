#include "singleList2.h"

LinkedList *listCreate()
{
    LinkedList *list = NULL;
    list = malloc(sizeof(*list));
    if(NULL == list)
    {
        return NULL;
    }

    list->dup = NULL;
    list->free = NULL;
    list->match = NULL;
    list->head = NULL;

    list->len = 0;
    list->typesize = 0;

    return list;
}

void listRelease(LinkedList *list)
{
    if(NULL == list)
    {
        return NULL;
    }

    listEmpty(list);

    free(list);

    list = NULL;
}

void listEmpty(LinkedList *list)
{
    if(NULL == list)
    {
        return;
    }

    while (NULL != list->head)
    {
        ListNode *pNode = list->head;
        list->head = pNode->next;
        if(NULL != list->free)
        {
            list->free(pNode->value);
        }
        else
        {
            free(pNode->value);
        }

        pNode->next = NULL;
        free(pNode);
        pNode = NULL;
    }
}

LinkedList *listAddNodeHead(LinkedList *list, void *value)
{
    if(NULL == list || NULL == value)
    {
        return list;
    }

    ListNode *node = NULL;
    node = malloc(sizeof(*node));
    if(NULL == node)
    {
        return list;
    }

    node->value = value;
    node->next = list->head;
    list->head = node;

    ++list->len;
    return list;
}

LinkedList *listAddNodeTail(LinkedList *list, void *value)
{
    if(NULL == list || NULL == value)
    {
        return list;
    }

    ListNode *node = NULL;
    node = malloc(sizeof(*node));
    if(NULL == node)
    {
        return list;
    }

    node->value = value;
    node->next = NULL;

    if(NULL == list->head && 0 == list->len)
    {
        list->head = node;
    }
    else
    {
        ListNode *tail = list->head;
        ListNode *pre = list->head;
        while (NULL != tail)
        {
            pre = tail;
            tail = tail->next;
        }
        pre->next = node;
    }

    ++list->len;

    return list;
}

LinkedList *listInsertNode(LinkedList *list, ListNode *oldNode, void *value, bool after)
{
    if(NULL == list || NULL == oldNode || NULL == value)
    {
        return list;
    }

    ListNode *node = NULL;
    node = malloc(sizeof(*node));
    node->value = value;
    node->next = NULL;

    if(after)
    {
        node->next = oldNode->next;
        oldNode->next = node;
    }
    else
    {
        ListNode *pre = list->head;
        while (pre->next != oldNode)
        {
            pre = pre->next;
        }

        if(NULL != pre)
        {
            pre->next = node;
            node->next = oldNode;
        }
    }

    ++list->len;

    return list;
}

//未设置释放函数时不做释放处理
void listDelNode(LinkedList *list, ListNode *node)
{
    if(NULL == list || NULL == node)
    {
        return;
    }

    ListNode *pre = list->head;
    ListNode *cur = list->head;
    while (NULL != cur && cur != node)
    {
        pre = cur;
        cur = cur->next;
    }

    //不在该链表中
    if(NULL == pre)
    {
        return;
    }

    pre->next = node->next;
    node->next = NULL;
    --list->len;

    if(NULL != list->free)
    {
        list->free(node->value);
        free(node);
        node = NULL;
    }
}

ListNode *listSearchKey(LinkedList *list, void *key)
{
    if(NULL == list)
    {
        return NULL;
    }

    ListNode *node = list->head;
    while (NULL != node)
    {
        if(NULL != list->match)
        {
            if(list->match(key, node->value) == 0)
            {
                return node;
            }
        }
        else
        {
            if(key == node->value)
            {
                return node;
            }
        }

        node = node->next;
    }

    return NULL;
}

ListNode *listIndex(LinkedList *list, long index)
{
    if(NULL == list)
    {
        return NULL;
    }

    if(index <= 0 || index > list->len)
    {
        return NULL;
    }

    ListNode *pNode = list->head;
    for (long i = 0; i < index; ++i)
    {
        pNode = pNode->next;
    }
    return pNode;
}
