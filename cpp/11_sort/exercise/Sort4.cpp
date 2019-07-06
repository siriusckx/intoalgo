#include <iostream>

void insertSort(int a[], int n, bool desc)
{
    for (size_t i = 0; i < n; i++)
    {
        int value = a[i];
        int j = i - 1;
        for (; j>=0; j--)
        {
            if(desc)
            {
                if(a[j] > value)
                {
                    a[j + 1] = a[j]; //移动元素
                }
                else
                {
                    break;
                }
            }
            else
            {
                if(a[j] < value)
                {
                    a[j + 1] = a[j]; //移动元素
                }
                else
                {
                    break;
                }
            }
        }
        a[j + 1] = value; //插入元素
    }
}


int main()
{
    int a[] = {2, 4, 1, 6, 7,3};
    insertSort(a, 6, true);
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;
    insertSort(a, 6, false);
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << a[i] << "\t";
    }
    
    
}