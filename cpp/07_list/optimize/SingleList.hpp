#ifndef __SINGLELIST_H__
#define __SINGLELIST_H__

#include <memory>

using namespace std;
namespace intoalgo
{
    //链表节点
    template<typename T>
    struct SingleListNode
    {
        SingleListNode *next;
        T *value;
    };

    //单链表
    template<typename T>
    class SingleList : public enable_shared_from_this<SingleList<T > >
    {
    public:
        SingleList();
        SingleList(long maxSize);
        virtual ~SingleList();

        SingleList *addHead(T *value);
        SingleList *addTail(T *value);
        SingleList *insert(SingleListNode<T> *oldNode, T *value, bool after);

        SingleList *delHead();
        SingleList *delTail();
        SingleList *delKey(T *value);
        SingleList *delIndex(long index);

        SingleListNode<T> *find(T *value);
        SingleListNode<T> *find(long index);

        SingleListNode<T> *begin();
        SingleListNode<T> *end();
        SingleListNode<T> *next();
        long size();

        SingleList *reverse();
        void clear();
        bool checkCycle();

    private:
        SingleListNode<T> *head;
        SingleListNode<T> *sentinel;
        long maxSize;
        long len;
    };
    
    template<typename T>
    SingleList<T>::SingleList():head(nullptr),sentinel(nullptr),maxsize(0),len(0)
    {
    }

    template<typename T>
    SingleList<T>::SingleList(long maxSize):head(nullptr),sentinel(nullptr),maxSize(maxSize),len(0)
    {
    }
    
    template<typename T>
    SingleList<T>::~SingleList()
    {
    }

    template<typename T>
    SingleList<T> * SingleList<T>::addHead(T *value)
    {
        SingleListNode<T> *pNode = new SingleListNode();
        pNode->value = value;
        pNode->next = this->head;
        this->head = pNode;

        ++this->len;

        return this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::addTail(T *value)
    {
        SingleListNode<T> *pNode = new SingleListNode();
        pNode->value = value;
        pNode->next = nullptr;

        if(nullptr == this->head && this->len == 0)
        {
            this->head = pNode;
        }
        else
        {
            SingleListNode<T> *pre = this->head;
            while (nullptr != pre->next)
            {
                pre = pre->next;
            }
            pre->next = pNode;
        }
        ++this->len;

        return this;
    }

    template<typename T>
    SingleList<T> *SingleList<T>::insert(SingleListNode<T> *oldNode, T *value, bool after)
    {
        if(nullptr == oldNode || nullptr == value)
        {
            return this;
        }

        SingleListNode<T> *pNode = new SingleListNode();
        pNode->value = value;
        
        if(after)
        {
            pNode->next = oldNode->next;
            oldNode->next = pNode->next;
        }
        else
        {
            SingleListNode<T> *pre = this->head;
            while (pre->next != oldNode)
            {
                pre = pre->next;
            }

            pNode->next = oldNode;
            pre->next = pNode;
        }
        ++this->len;

        return this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::delHead()
    {
        if(this->len == 0)
        {
            return this;
        }
        SingleListNode<T> *pNode = this->head;
        this->head = this->head->next;
        //TODO 释放pNode中value的对象
        delete (pNode);
        pNode = nullptr;
        --this->len;
        return this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::delTail()
    {
        if(this->len == 0)
        {
            return this;
        }
        SingleListNode *pre= this->head;
        SingleListNode *tail = this->head;
        while (nullptr != tail->next)
        {
            pre = tail;
            tail = tail->next;
        }

        pre->next = nullptr;

        //TODO 释放尾结点对应value的内存
        delete (tail);
        tail = nullptr;
        --this->len;

        return this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::delKey(T *value)
    {
        if(nullptr == value)
        {
            return this;
        }

        SingleListNode<T> *pre = this->head;
        SingleListNode<T> *cur = this->head;
        while (nullptr != cur && cur->value != value)
        {
            pre = cur;
            cur = cur->next;
        }
        
        //说明value在链表中
        if(nullptr != cur)
        {
            pre->next = cur->next;
            
            //TODO 根据设计情况，对应节点的值要进行释放
            cur->next = nullptr;
            delete (cur);
            cur = nullptr;
            --this->len;
        }
        return this;
    }
        
    template<typename T>
    SingleList<T> * SingleList<T>::delIndex(long index)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::find(T *value)
    {
        return NULL;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::find(long index)
    {
        return NULL;
    }


    template<typename T>
    SingleListNode<T> * SingleList<T>::begin()
    {
        return this->head;
    }
    

    template<typename T>
    SingleListNode<T> * SingleList<T>::end()
    {
        SingleListNode *pNode = this->head;
        while (nullPtr != pNode->next)
        {
            pNode = pNode->next;
        }
        
        return pNode;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::next()
    {
        if(nullptr == this->sentinel)
        {
            this->sentinel = this->head;
        }
        else
        {
            this->sentinel = this->sentinel->next;
        }
        return this->sentinel;
    }

    template<typename T>
    long SingleList<T>::size()
    {
        return this->len;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::reverse()
    {
        SingleListNode *head = this->head;
        SingleListNode *pre = nullptr;
        SingleListNode *next = nullptr;
        while (nullptr != head)
        {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        
        return this;
    }

    template<typename T>
    void SingleList<T>::clear()
    {

    }

    template<typename T>
    bool SingleList<T>::checkCycle()
    {
        return false;
    }
}
#endif //!__SINGLELIST_H__