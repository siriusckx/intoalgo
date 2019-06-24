#ifndef QUEUE_CIRCULAR_QUEUE_HPP_
#define QUEUE_CIRCULAR_QUEUE_HPP_

template <typename T>
class CircularQueue
{
private:
    T *m_items = nullptr;
    size_t m_capacity = 0;
    size_t m_head = 0;
    size_t m_tail = 0;

public:
    CircularQueue() = delete;
    CircularQueue(const size_t capacity):m_capacity(capacity)
    {
        m_items = new T[m_capacity];
    }
    virtual ~CircularQueue()
    {
        if(nullptr != m_items)
        {
            delete[] m_items;
            m_items = nullptr;
            m_head = 0;
            m_tail = 0;
        }
    }
    CircularQueue(const CircularQueue& other):m_capacity(other.m_capacity)
    {
        m_items = new T[m_capacity];
        for (size_t i = other.m_head; i < other.m_tail; i++)
        {
            m_items[i] = other.m_items[i];
        }
    }

    CircularQueue& operator=(const CircularQueue& rhs)
    {
       delete[] m_items;
       m_head = 0;
       m_tail = 0;
       m_capacity = rhs.m_capacity;

       for (size_t i = rhs.m_head; i < rhs.m_tail; i++)
       {
           enqueue(rhs.m_items[i]);
       }

       return *this;
    }

    CircularQueue(CircularQueue &&other):m_items(other.m_items),
                                         m_head(other.m_head),
                                         m_tail(other.m_tail),
                                         m_capacity(other.m_capacity){
        other.m_items = nullptr;
        other.m_head = 0;
        other.m_tail = 0;
        other.m_capacity = 0;
    }

    CircularQueue& operator=(CircularQueue &&rhs)
    {
        delete[] m_items;
        m_items = rhs.m_items;
        m_capacity = rhs.m_capacity;
        m_head = rhs.m_head;
        m_tail = rhs.m_tail;

        rhs.m_items = nullptr;
        rhs.m_capacity = 0;
        rhs.m_head = 0;
        rhs.m_tail = 0;

        return *this;
    }
public:
    void enqueue(T item)
    {
        if((m_tail + 1)%m_capacity == m_head)
        {
            throw "Push data into a full queue";
        }
        m_items[m_tail] = item;
        m_tail = (m_tail + 1) % m_capacity;
    }

    T head() const
    {
        if(m_tail == m_head)
        {
            throw "Fetch data from an empty queue!";
        }
        return m_items[m_head];
    }

    void dequeue()
    {
        if(m_tail == m_head)
        {
            throw "Pop data from an empty queue!";
        }
        m_head = (m_head + 1) % m_capacity;
    }

public:
    template<typename UnaryFunc>
    void traverse(UnaryFunc do_traverse)
    {
        if(0 == m_capacity)
            return;
        for (size_t i = m_head; i%m_capacity != m_tail; i++)
        {
            do_traverse(m_items[i % m_capacity]);
        }
    }
};

#endif //!QUEUE_CIRCULAR_QUEUE_HPP_