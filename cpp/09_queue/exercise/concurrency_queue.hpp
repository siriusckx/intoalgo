#ifndef QUEUE_CONCURRENCY_QUEUE_HPP_
#define QUEUE_CONCURRENCY_QUEUE_HPP_

#include <queue>
#include <mutex>
#include <condition_variable>
#include <memory>

template <typename T>
class ConcurrencyQueue
{
public:
    using value_type = T;
    using container_type = std::queue<value_type>;
    using size_type = typename container_type::size_type;

private:
    container_type m_container;
    mutable std::mutex m_mutex;
    std::condition_variable m_containerCond;

public:
    ConcurrencyQueue() = default;
    ConcurrencyQueue(const ConcurrencyQueue &) = default;
    ConcurrencyQueue(ConcurrencyQueue &&) = default;
    ConcurrencyQueue &operator=(const ConcurrencyQueue &) = default;
    ConcurrencyQueue &operator=(ConcurrencyQueue &&) = default;

private:
    bool empty_() const { return m_container.empty(); }

public:
    bool empty() const
    {
        std::lock_guard<std::mutex> lg(m_mutex);
        return m_container.empty();
    }

    void push(value_type item)
    {
        std::lock_guard<std::mutex> lg(m_mutex);
        m_container.push(std::move(item));
        m_containerCond.notify_one();
    }

    void waitAndPop(value_type& out)
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (empty_())
        {
            m_containerCond.wait(lock);
        }
        out = std::move(m_container.front());
        m_container.pop();
    }

    std::shared_ptr<value_type> waitAndPop()
    {
        std::unique_lock<std::mutex> lock(m_mutex);
        while (empty_())
        {
            m_containerCond.wait(lock);
        }
        auto res = std::make_shared<value_type>(std::move(m_container.front()));
        m_container.pop();
        return res;
    }

    bool tryPop(value_type& out)
    {
        std::lock_guard<std::mutex> lg(m_mutex);
        if(empty_())
        {
            return false;
        }
        out = std::move(m_container.front());
        m_container.pop();
        return true;
    }

    std::shared_ptr<value_type> tryPop()
    {
        std::lock_guard<std::mutex> lg(m_mutex);
        if(empty_())
        {
            return nullptr;
        }
        auto res = std::make_shared<value_type>(std::move(m_container.front()));
        m_container.pop();
        return res;
    }
};

#endif