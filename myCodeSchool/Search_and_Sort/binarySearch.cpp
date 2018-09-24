#include <iostream>
using namespace std;

int binarySearch(int *arr, int x, int size)
{
    int start = 0;
    int end = size - 1;

    while (start <= end)
    {
        //int mid = end + (end - start) / 2;  **More correct. Avoids overflow.
        int mid = (start + end) / 2;
        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            end = mid - 1;
        else if (arr[mid] < x)
            start = mid + 1;
    }
    return -1;
}

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int num;
    cout << "Enter number: " << endl;
    cin >> num;
    int pos = binarySearch(arr, num, 5);
    if (pos != -1)
        cout << "The number is at index: " << pos << endl;
    else
        cout << "Number not found" << endl;
    return 0;
}