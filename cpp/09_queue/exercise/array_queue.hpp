#ifndef QUEUE_ARRAY_QUEUE_HPP_
#define QUEUE_ARRAY_QUEUE_HPP_

template<typename T>
class ArrayQueue
{
private:
    T *m_items = nullptr;
    size_t m_capacity = 0;
    size_t m_head = 0;
    size_t m_tail = 0;

public:
    ArrayQueue() = delete;
    ArrayQueue(const size_t capacity):m_capacity(capacity)
    {
        m_items = new T[m_capacity];
    }
    ~ArrayQueue() 
    {
        if(nullptr != m_items)
        {
            delete[] m_items;
            m_items = nullptr;
        }
    }
    ArrayQueue(const ArrayQueue& other):m_capacity(other.m_capacity)
    {
        m_items = new T[m_capacity];
        for (size_t i = other.m_head; i < other.m_tail; ++i)
        {
            enqueue(other.m_items[i]);
        }
    }
    ArrayQueue& operator=(const ArrayQueue& rhs)
    {
        delete[] m_items;
        m_head = 0;
        m_tail = 0;
        m_capacity = rhs.m_capacity;
        m_items = new T[m_capacity];
        for (size_t i = rhs.m_head; i < rhs.m_tail; ++i)
        {
            enqueue(rhs.m_items[i]);
        }
        return *this;
    }
    ArrayQueue(ArrayQueue&& other):m_items(other.m_items),
                                   m_capacity(other.m_capacity),
                                   m_head(other.m_head),
                                   m_tail(other.m_tail){
        other.m_items = nullptr;
        other.m_capacity = 0;
        other.m_head = 0;
        other.m_tail = 0;
    }
    ArrayQueue& operator=(ArrayQueue&& rhs)
    {
        delete m_items;
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
        if(m_tail == m_capacity)
        {
            throw "Push data into a full queue!";
        }
        m_items[m_tail++] = item;
    }

    T head() const
    {
        if(m_head != m_tail)
        {
            return m_items[m_head];
        }
        else
        {
            throw "Fetch data from an empty queue!";
        }
    }

    void dequeue()
    {
        if(m_head != m_tail)
        {
            ++m_head;
        }
        else
        {
            throw "Pop data from an empty queue!";
        }
        
    }

public:
    template<typename UnaryFunc>
    void traverse(UnaryFunc do_traverse)
    {
        for (size_t i = m_head; i < m_tail; ++i)
        {
            do_traverse(m_items[i]);
        }
        
    }

};
#endif //! QUEUE_ARRAY_QUEUE_HPP_