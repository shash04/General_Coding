// Solution for two questions:
// Q1) Find first and last occurence of a number in a sorted list with duplicates
// Q2) Find count of an element in a sorted list with duplicates

#include <iostream>
using namespace std;

int getFirstOrLastOccurence(int *arr, int x, int size, int pos)
{
    int low = 0;
    int high = size - 1;
    int result = -1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x)
        {
            result = mid;
            !pos ? high = mid - 1 : low = mid + 1;
        }
        else if (x < arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return result;
}

int main()
{
    int arr[8] = {2, 10, 10, 10, 10, 10, 10, 50};
    int num;
    cout << "Enter number: " << endl;
    cin >> num;
    int first = getFirstOrLastOccurence(arr, num, 8, 0);
    int last = getFirstOrLastOccurence(arr, num, 8, 1);
    if (first != -1 && last != -1)
    {
        cout << "First occurence : " << first << endl;
        cout << "Last occurence : " << last << endl;
        int numberOfOccurences = last - first + 1;
        cout << "Total number of occurences = " << numberOfOccurences << endl;
    }
    else
        cout << "Number not found" << endl;
    return 0;
}