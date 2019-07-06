#include <iostream>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void bubbleSort(int a[], int n, bool asc)
{
    if(n <= 0)
        return;
    
    for (size_t i = 0; i < n; i++)
    {
        bool hasSwap = false;
        for (size_t j = 0; j+1 < n-i; j++)
        {
            if(asc)
            {
                if(a[j+1]<a[j])
                {
                    swap(&a[j + 1], &a[j]);
                    hasSwap = true;
                }
            }
            else
            {
                if(a[j+1]>a[j])
                {
                    swap(&a[j + 1], &a[j]);
                    hasSwap = true;
                }
            }
        }
        if(!hasSwap)
        {
            break;
        }
    }
}

int main()
{
    int a[] = {1, 2, 5, 2, 1, 4};
    bubbleSort(a, 6, true);
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;

    bubbleSort(a, 6, false);
    for (size_t i = 0; i < 6; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;
}