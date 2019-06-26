#ifndef QUEUE_LINKED_QUEUE_HPP_
#define QUEUE_LINKED_QUEUE_HPP_

#include <memory>

template <typename T>
struct Node
{
    using ptr_t = std::shared_ptr<Node<T> >;
    T m_data;
    ptr_t m_next;

    Node(T data):m_data(data), m_next(nullptr){}
    Node() : next(nullptr){}
};

template <typename T>
class LinkedQueue
{
public:
    using node_type= Node<T>;
    using node_ptr_t = typename node_type::ptr_t;

private:
    node_ptr_t m_head = nullptr;
    node_ptr_t m_beforeTail = nullptr;

public:
    LinkedQueue() = default;
    ~LinkedQueue() = default;
    LinkedQueue(const LinkedQueue &) = default;
    LinkedQueue& operator=(const LinkedQueue &) = default;
    LinkedQueue(LinkedQueue &&) = default;
    LinkedQueue& operator=(LinkedQueue &&) = default;

public:
    void enqueue(T item)
    {
        if (nullptr == m_head)
        {
            m_head->next = std::make_shared<node_type>(item);
            m_beforeTail = m_head;
        }
        else
        {
            m_beforeTail->next = std::make_shared<node_type>(item);
            m_beforeTail = m_beforeTail->next;
        }
    }

    T head() const
    {
        if(nullptr == m_head)
        {
            throw "Fetch data from empty queue!";
        }
        return m_head->data;
    }

    void dequeue()
    {
        if(nullptr == m_head)
        {
            throw "Fetch data from empty queue!";
        }
        m_head = m_head->next;
        if(nullptr == m_head)
        {
            m_beforeTail = nullptr;
        }
    }
};

#endif