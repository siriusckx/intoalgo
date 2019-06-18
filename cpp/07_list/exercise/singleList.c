#include "singleList.h"

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

    return list;
}

//释放
void listRelease(LinkedList *list)
{
    if(NULL == list)
    {
        return;
    }

    listEmpty(list);

    free(list);

    list = NULL;
}

//链表元素置空
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
    if(NULL == list || NULL == list)
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

    //列表为空，直接针头节点设置为新增的节点即可
    if(NULL == list->head && list->len == 0)
    {
        list->head = node;
    }
    else
    {
        //找到对应的尾节点位置
        ListNode *tail = list->head;
        ListNode *pre = list->head;
        while (NULL != tail)
        {
            pre = tail;
            tail = tail->next;
        }

        //将真正的尾节点的位置的一下个节点指向，新添加的一个节点
        pre->next = node;
    }

    //链表长度增加1
    ++list->len;

    return list;
}

LinkedList *listInsertNode(LinkedList *list, ListNode *oldNode, void *value, bool after)
{
    if(NULL == list || NULL == value)
    {
        return list;
    }

    ListNode *pNode = NULL;
    pNode = malloc(sizeof(*pNode));
    if (NULL == pNode)
    {
        return list;
    }
    pNode->value = value;

    if(after)
    {
        pNode->next = oldNode->next;
        oldNode->next = pNode;
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
            pNode->next = pre->next;
            pre->next = pNode;
        }
    }

    ++list->len;
    return list;
}

//没设置释放函数时不做释放处理
void listDelode(LinkedList *list, ListNode *node)
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

LinkedList *listRewind(LinkedList *list)
{
    if(NULL == list)
    {
        return NULL;
    }

    ListNode *head = list->head;
    ListNode *pre = NULL;
    ListNode *next = NULL;

    while (NULL != head)
    {
        next = head->next;
        head->next = pre;
        pre = head;
        head = next;
    }

    list->head = pre;
    return list;
}



























