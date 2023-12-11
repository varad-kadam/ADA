#include <stdio.h>
#include <time.h>

// Function prototype
int partition(int arr[], int p, int r);

void quicksort(int arr[], int p, int r)
{
    int q;
    if (p < r)
    {
        q = partition(arr, p, r);
        quicksort(arr, p, q - 1);
        quicksort(arr, q + 1, r);
    }
}

int partition(int arr[], int p, int r)
{
    int x = arr[r];
    int i = p - 1;
    for (int j = p; j < r; j++)
    {
        if (arr[j] <= x)
        {
            i = i + 1;
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
    }

    int t = arr[r];
    arr[r] = arr[i + 1];
    arr[i + 1] = t;
    return i + 1;
}

int main()
{
    int arr[100], n, p = 0;
    clock_t start, end;
    double time;

    printf("Enter the size of array:");
    scanf("%d", &n);
    int r = n - 1;

    printf("Enter the numbers:");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nArray elements are:");
    for (int i = 0; i < n; i++)
    {
        printf("%d", arr[i]);
    }
    printf("\n");

    start = clock();
    quicksort(arr, p, r);
    end = clock();

    time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\narray after sorting:");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\nTime taken is %lf", time);
    
    return 0;
}
