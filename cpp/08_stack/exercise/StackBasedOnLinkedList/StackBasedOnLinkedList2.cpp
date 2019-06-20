#include "StackBasedOnLinkedList2.h"

namespace intoalgo
{
    template<class T>
    LinkedListStack<T>::LinkedListStack():count(0), head(new LinkedNode())
    {
    }

    template<class T>
    LinkedListStack<T>::~LinkedListStack()
    {
        while (nullptr != this->head->next)
        {
            LinkedNode *node = this->head->next;
            this->head->next = node->next;
            delete node;
        }
        delete head;
        this->count = 0;
    }

    template<class T>
    void LinkedListStack<T>::push(const T &data)
    {
        LinkedNode *node = new LinkedNode();
        node->data = data;
        node->next = this->head->next;
        this->head->next = node;
        ++this->count;
    }

    template<class T>
    T LinkedListStack<T>::peek()
    {
        if(nullptr == this->head->next || this->count == 0)
        {
            return NULL;
        }

        return this->head->next->data;
    }

    template<class T>
    T LinkedListStack<T>::pop()
    {
        if(nullptr == this->head->next || this->count == 0)
        {
            return NULL;
        }

        LinkedNode *node = this->head -> next;
        this->head->next = node->next;
        T data = node->data;
        delete node;
        --this->count;

        return data;
    }

    template<class T>
    int LinkedListStack<T>::size() const
    {
        return this->count;
    }
} // namespace nameintoalgo

