#ifndef QUEUE_BLOCK_QUEUE_HPP_
#define QUEUE_BLOCK_QUEUE_HPP_

#include <queue>
#include <mutex>
#include <condition_variable>

template <typename T>
class BlockQueue 
{
public:
    using value_type = T;
    using container_type = std::queue<value_type>;
    using size_type = typename container_type::size_type;
private:
    size_type m_capacity = 0;
    container_type m_container;
    mutable std::mutex m_mutex;
    mutable std::condition_variable m_notEmpty;
    mutable std::condition_variable m_notFull;
public:
    BlockQueue() = delete;
    BlockQueue(const size_type capacity):m_capacity(capacity){}
    BlockQueue(const BlockQueue &) = default;
    BlockQueue(BlockQueue &&) = default;
    BlockQueue &operator=(const BlockQueue &) = default;
    BlockQueue &operator=(BlockQueue &&) = default;
private:
    bool empty() const { return m_container.empty(); }
    bool full() const { return not(m_container.size < m_capacity); }
public:
    void put(const value_type& item)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (full())
        {
            m_notFull.wait(lock);
        }
        m_container.push(item);
        m_notEmpty.notify_one();
    }

    void take(value_type& out)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (empty())
        {
            m_notEmpty.wait(lock);
        }
        out = m_container.front();
        m_container.pop();
        m_notFull.notify_one();
    }

    template<typename Duration>
    bool put_for(const value_type& item, const Duration& d)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_notFull.wait_for(lock, d, [&]() { return not full(); }))
        {
            m_container.push(item);
            m_notEmpty.notify_one();
            return true;
        }
        else
        {
            return false;
        }
    }

    template<typename Duration>
    bool take_for(const Duration& d, value_type& out)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        if (m_notEmpty.wait_for(lock, d, [&]() { return not empty(); }))
        {
            out = m_container.front();
            m_container.pop();
            m_notFull.notify_one();
            return true;
        }
        else
        {
            return false;
        }
    }
};

#endif
