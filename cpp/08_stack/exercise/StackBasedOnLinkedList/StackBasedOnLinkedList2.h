#ifndef __STACKBASEDONLINKEDLIST2_H__
#define __STACKBASEDONLINKEDLIST2_H__

namespace intoalgo
{
    template <typename T>
    class LinkedListStack 
    {
    private:
        int count; //栈中元素的数量
        struct LinkedNode
        {
            T data;
            LinkedNode *next;
        };
        LinkedNode *head; //单链表的头指针，不带头节点

    public:
        LinkedListStack();
        virtual ~LinkedListStack();

        void push(const T &data); //入栈
        T pop(); //出栈，删除栈顶元素
        T peek(); //返回栈顶元素，即出栈，不删除栈顶元素
        int size() const;
    };
    
}
#endif