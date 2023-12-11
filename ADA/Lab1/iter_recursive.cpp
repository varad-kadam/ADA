#include <iostream>
#include <ctime>

using namespace std;

// Linear Search function
void linearSearch(int list[], int n, int target)
{
    int I = 0;
    int flag = 0;

    while (I < n)
    {
        if (list[I] == target)
        {
            flag = 1;
            break;
        }
        I = I + 1;
    }

    if (flag == 1)
    {
        cout << "Target found" << endl;
    }
    else
    {
        cout << "Target not found" << endl;
    }
}

// Binary Search function
int binarySearch(int a[], int n, int x)
{
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (x < a[mid])
            high = mid - 1;
        else if (x > a[mid])
            low = mid + 1;
        else
            return mid; // Element found at index mid
    }

    return -1; // Element not found
}

// Binary Search with recursion function
int binarySearchRecursive(int a[], int low, int high, int x)
{
    if (low == high)
    {
        if (x == a[low])
            return low;
        else
            return -1; // Element not found
    }
    else
    {
        int mid = (low + high) / 2;
        if (x == a[mid])
            return mid; // Element found at index mid
        else if (x < a[mid])
            return binarySearchRecursive(a, low, mid - 1, x);
        else
            return binarySearchRecursive(a, mid + 1, high, x);
    }
}

int main()
{
    int choice;
    cout << "Choose a search technique:" << endl;
    cout << "1. Linear Search" << endl;
    cout << "2. Binary Search" << endl;
    cout << "3. Binary Search with Recursion" << endl;
    cin >> choice;

    int n, x;
    cout << "Enter the number of elements in the list or array: ";
    cin >> n;

    int arr[n];

    cout << "Enter the elements in increasing order:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the element to search for: ";
    cin >> x;

    clock_t start_time, end_time;
    double execution_time;

    switch (choice)
    {
    case 1:
        start_time = clock();
        linearSearch(arr, n, x);
        end_time = clock();
        break;
    case 2:
        start_time = clock();
        // Use binarySearch and store the result
        int binaryResult;
        binaryResult = binarySearch(arr, n, x);
        end_time = clock();
        if (binaryResult != -1)
        {
            cout << "Element " << x << " found at index " << binaryResult << endl;
        }
        else
        {
            cout << "Element " << x << " not found in the array" << endl;
        }
        break;
    case 3:
        start_time = clock();
        // Use binarySearchRecursive and store the result
        int recursiveResult;
        recursiveResult = binarySearchRecursive(arr, 0, n - 1, x);
        end_time = clock();
        if (recursiveResult != -1)
        {
            cout << "Element " << x << " found at index " << recursiveResult << endl;
        }
        else
        {
            cout << "Element " << x << " not found in the array" << endl;
        }
        break;
    default:
        cout << "Invalid choice" << endl;
        return 1;
    }
    execution_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    cout << "Execution time: " << execution_time << " seconds" << endl;

    return 0;
}