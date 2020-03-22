#include <stdio.h>

void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;
}

int     digit_cmp(int a, int b)
{
    return (a - b);
}

void    coctail_sort(int* digits[], int len)
{
    int left;
    int right;

    left = 0;
    right = len - 1;
    while (left < right)
    {
        for (int i = 0; i < len; i += 1)
        {
            if (i < (len - 1))
            {
                if (digit_cmp(digits[i], digits[i + 1]) > 0)
                {
                    swap(&digits[i], &digits[i + 1]);
                }
            }
        }
        right -= 1;
        for (int i = len - 1; i > 0; i -= 1)
        {
            if (digit_cmp(digits[i], digits[i - 1]) < 0)
            {
                swap(&digits[i], &digits[i - 1]);
            }
        }
        left += 1;
    }
}

int     main()
{
    int digits[5] = { 1,15,10,0,22 };
    coctail_sort(digits, 5);
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", digits[i]);
    }
}
