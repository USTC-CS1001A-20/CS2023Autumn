#include <stdio.h>

// selection sort
// sign == 1 for ascending order
int selection_sort(int a[100], int n, int sign)
{
    int i, j, temp;
    int count = 0;
    int min;
    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (sign == 1)
            {
                if (a[j] < a[min])
                {
                    min = j;
                }
            }
            else
            {
                if (a[j] > a[min])
                {
                    min = j;
                }
            }
            count++;
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
    }
    return count;
}

// bubble sort
int bubble_sort(int a[100], int n, int sign)
{
    int i, j, temp;
    int count = 0;
    for (i = 0; i < n - 1; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (sign == 1)
            {
                if (a[j] > a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
            else
            {
                if (a[j] < a[j + 1])
                {
                    temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }
            count++;
        }
    }
    return count;
}

// insertion sort
int insertion_sort(int a[100], int n, int sign)
{
    int i, j, temp;
    int count = 0;
    for (i = 1; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        if (sign == 1)
        {
            while (j >= 0 && a[j] > temp)
            {
                // count++;
                a[j + 1] = a[j];
                j--;
            }
        }
        else
        {
            while (j >= 0 && a[j] < temp)
            {
                // count++;
                a[j + 1] = a[j];
                j--;
            }
        }
        a[j + 1] = temp;
        if(j < 0) count+= i - 1 - j;
        else count+= i - j;
    }
    return count;
}

int test(){
    int a, b, c, d, e, *x, f;
    -a + b - c * !&d - 0.3;
    a + b > c && d <= e + b - c * *x;
    a || b | c && d ^ e || f & 0LL | 1;
    -!*&a;
    int ___;
    !~a;
    ~!a;
    1>0 & 1;
    a < = b;
}

int main()
{
    int a[100], n, i;
    scanf("%d", &n);
    int sign;
    scanf("%d", &sign); // 1 for ascending order, 0 for descending order
    // printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    int b[100];
    for (i = 0; i < n; i++)
    {
        // printf("%d ",b[i]);
        b[i] = a[i];
    }
    int temp = selection_sort(b, n, sign);
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
        b[i] = a[i];
    }
    printf("%d\n", temp);
    temp = bubble_sort(b, n, sign);
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
        b[i] = a[i];
    }
    printf("%d\n", temp);
    temp = insertion_sort(b, n, sign);
    for (i = 0; i < n; i++)
    {
        printf("%d ", b[i]);
        b[i] = a[i];
    }
    printf("%d", temp);
    return 0;
}