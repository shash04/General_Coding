// ************************************************************************************
// Insertion Sort algorithm:
// Compare consecutive elements for each iteration. If smaller element is placed after
// greater element, shift the array to right until the smaller element can be fitted
// such that it is at final sorted position.
// Worst case Complexity: O(n^2)
//
// Input Format:
//  There will be two lines of input:
//      the size of the array (int)
//      a list of numbers (int) that makes up the array
// Output Format:
//  On each line, print the entire array after every iteration
// Constraints:
//  1 <= s <= 1000
// ************************************************************************************

#include <iostream>
using namespace std;

void printArray(int ar_size, int *ar)
{
    for(int i=0; i<ar_size; i++){
        cout<<ar[i] << " ";
    }
    cout<<endl;
}

void insertionSort(int ar_size, int *  ar)
{
    for(int i=0; i<ar_size-1; i++)
    {
        if(ar[i]>ar[i+1])
        {
            int j = i;
            int smaller = ar[i+1];
            while(smaller<ar[j] && j >= 0)
            {
                ar[j+1] = ar[j];
                j--;
            }
            ar[j+1] = smaller;
        }
        printArray(ar_size, ar);
    }
}

int main(void)
{
    int _ar_size;
    cin >> _ar_size;
    int _ar[_ar_size], _ar_i;
    for(_ar_i = 0; _ar_i < _ar_size; _ar_i++)
    { 
        cin >> _ar[_ar_i];
    }
   insertionSort(_ar_size, _ar); 
   return 0;
}
