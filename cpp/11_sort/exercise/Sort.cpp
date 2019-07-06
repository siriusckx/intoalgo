#include <iostream>

void swap(int *x, int *y)
{
    int t = *x;
    *x = *y;
    *y = t;
}

void bubbleSort(int a[], int n, bool asc)
{
    if (n <= 0)
        return;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j + 1 < n - i; ++j)
        {
            //升序
            if(asc)
            {
                if (a[j + 1] < a[j])
                {
                    swap(&a[j + 1], &a[j]);
                }
            }
            else
            {
                if(a[j + 1] > a[j])
                {
                    swap(&a[j + 1], &a[j]);
                }
            }
            
        }
    }
}

int main()
{
    int a[6] = {3, 4, 2, 1, 5, 2};
    bubbleSort(a, 6, true);
    for (int i = 0; i < 6; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;

    bubbleSort(a, 6, false);
    for (int i = 0; i < 6; i++)
    {
        std::cout << a[i] << "\t";
    }
    std::cout << std::endl;

    return 0;
}
