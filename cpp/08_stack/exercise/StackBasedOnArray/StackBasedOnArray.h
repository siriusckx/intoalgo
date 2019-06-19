#ifndef __STACKBASEDONARRAY_H__
#define __STACKBASEDONARRAY_H__

namespace intoalgo
{
   template<class T>
   class ArrayStack
   {
    public:
        ArrayStack();
        ArrayStack(int count);
        virtual ~ArrayStack();
        void push(T data); //入栈
        T pop();           //出栈
        T peek();          //返回栈顶元素
        int stackSize();
        int stackMaxSize();
    private:
        int flag;//栈顶标签，指向栈顶
        int count;//栈的容量
        T *array;//指针
   };
} // namespace intoalgo

#endif