/**
 * 1)顺序栈的操作，入栈和出栈
 * 2)采用模板的方法实现存储任意类型的数据
 * 3)采用数组的栈，支持动态扩容，每次扩容1.5倍，初始栈的大小是10
 */
#include <iostream>
#include "StackBasedOnArray.h"
using namespace std;

namespace intoalgo
{
    template<class T>
    ArrayStack<T>::ArrayStack():flag(0), count(10)
    {
        this->array = new T[this->count];
        if(!this->array)
        {
            cout << " array malloc memory failure!" << endl;
        }
    }

    template<class T>
    ArrayStack<T>::ArrayStack(int count):flag(0), count(count)
    {
        this->array = new T[this->count];
        if(!this->array)
        {
            count << " array malloc memory failure! " << endl;
        }
    }

    template<class T>
    ArrayStack<T>::~ArrayStack()
    {
        this->count = 0;
        this->flag = 0;
        if(this->array)
        {
            delete[] this->array;
            this->array = nullptr;
        }

    }

    template<class T>
    void ArrayStack<T>::push(T data)
    {
        if(this->flag == this->count)
        {
            cout << "stack is full need to enlarge 1.5x" << endl;
            this->count = this->count * 1.5;
            T *temp = new T[this->count];
            for (int i = 0; i < this->flag; i++)
            {
                temp[i] = this->array[i];
            }
            delete[] this->array;
            temp[this->flag] = data;
            this->flag++;
            this->array = temp;
        }
        else
        {
            this->array[this->flag] = data;
            this->flag++;
        }
    }

    //弹出并删除栈顶元素，并不需要将元素真正的删除，而是将栈顶标识减1
    template<class T>
    T ArrayStack<T>::pop()
    {
        if(this->flag == 0)
        {
            return nullptr;
        }
        this->flag--;
        return this->array[this->flag];
    }

    //弹出栈顶元素，将栈顶元素弹出，标识不需要减1
    template<class T>
    T ArrayStack<T>::peek()
    {
        if(this->flag == 0)
        {
            return nullptr;
        }
        return this->array[this->flag - 1];
    }

    template<class T>
    int ArrayStack<T>::stackSize()
    {
        return this->flag;
    }

    template<class T>
    int ArrayStack<T>::stackMaxSize()
    {
        return this->count;
    }
}