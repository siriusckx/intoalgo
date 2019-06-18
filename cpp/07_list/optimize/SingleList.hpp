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

        SingleList *delHead(T *value);
        SingleList *delTail(T *value);
        SingleList *delKey(T *value);
        SingleList *delIndex(long index);

        SingleListNode *find(T *value);
        SingleListNode *find(long index);

        SingleListNode *head();
        SingleListNode *tail();
        SingleListNode *next();
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
    SingleList<T>::SingleList()
    {
    }

    template<typename T>
    SingleList<T>::SingleList(long maxSize)
    {

    }
    
    template<typename T>
    SingleList<T>::~SingleList()
    {
    }

    template<typename T>
    SingleList<T> * SingleList<T>::addHead(T *value)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::addTail(T *value)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleList<T> *SingleList<T>::insert(SingleListNode<T> *oldNode, T *value, bool after)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::delHead(T *value)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::delTail(T *value)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::delKey(T *value)
    {
        return shared_from_this;
    }
        
    template<typename T>
    SingleList<T> * SingleList<T>::delIndex(long index)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::find(T *value)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::find(long index)
    {
        return shared_from_this;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::head()
    {
        return nullptr;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::tail()
    {
        return nullptr;
    }

    template<typename T>
    SingleListNode<T> * SingleList<T>::next()
    {
        return nullptr;
    }

    template<typename T>
    long SingleList<T>::size()
    {
        return 0;
    }

    template<typename T>
    SingleList<T> * SingleList<T>::reverse()
    {
        return shared_from_this;
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
#endif