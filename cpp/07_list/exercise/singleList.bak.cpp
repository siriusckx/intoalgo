#include <cstring>
#include <memory>
#include <iostream>
#include "singleList.bak.h"

using namespace std;

LinkedListPtr listCreate()
{
    LinkedListPtr list(new LinkedList());

    list->dup = nullptr;
    list->free = nullptr;
    list->match = nullptr;

    list->head = nullptr;
    list->len = 0;

    return list;
}

//释放
void listRelease(LinkedListPtr list)
{
    if(nullptr == list)
    {
        return;
    }

    listEmpty(list);
    list = nullptr;
}

void listEmpty(LinkedListPtr list)
{
    if(nullptr == list)
    {
        return;
    }

    while (nullptr != list->head)
    {
        ListNodePtr pNode = list->head;
        list->head = pNode->next;
        if(nullptr != list->free)
        {
            list->free(pNode->value);
        }
        else
        {
            
        }
        
    }
    
}


int main()
{
   listCreate();
   return 0;
}