/**
 * 1) 链式栈的操作：入栈，出栈以及返回栈的大小
 * 2）采用模板的方法实现存储任意类型的数据
 * 3）采用单链表实现栈
 * 4) pop和peek出栈的返回值稍微有点问题，当栈为空的时候，返回null，cpp默认返回的是0
 *    * 改进方法就是不用函数的返回值返回栈顶元素，而是采用参数列表的形式返回
 */
#include <iostream>
#include "StackBasedOnLinkedList.h"
using namespace std;

namespace intoalgo
{
    template<class T>
    LinkedListStack<T>::LinkedListStack():count(0), head(new LinkedNode())
    {
    }

    template<class T>
    LinkedListStack<T>::~LinkedListStack()
    {
        while(nullptr != this->head->next)
        {
            LinkedNode *node = this->head->next;
            this->head->next = node->next->next;
            delete node;
        }
        delete head;
        this->head = NULL;
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
    T LinkedListStack<T>::pop()
    {
        if(nullptr == this->head->next || this->count == 0)
        {
            return NULL;
        }
        LinkedNode *node = this->head->next;
        T data= node->data;
        this->head->next = node->next;
        delete node;
        --this->count;
        return data;
    }

    template<class T>
    T LinkedListStack<T>::peek()
    {
        if(nullptr == this->head->next || this->count == 0)
        {
            return NULL;
        }

        return this->head->data;
    }

    template<class T>
    int LinkedListStack<T>::size() const
    {
        return this->count;
    }
}