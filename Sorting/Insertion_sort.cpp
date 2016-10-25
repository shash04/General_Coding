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
