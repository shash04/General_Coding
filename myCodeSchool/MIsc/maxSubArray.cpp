#include <iostream>
using namespace std;

int maxSubArray(int *arr, int size)
{
    int ans = 0;
    int sum = 0;

    for(int i=0; i<size; i++)
    {
        if(( sum + arr[i] ) > 0)
        {
            sum += arr[i];
        }
        else
        {
            sum = 0;
        }
        ans = max(ans, sum);
    }
    return ans;
}

int main()
{
    int arr[4] = {3, -2, 5, -1};
    cout<<"Maximum sum of sub-array = "<<maxSubArray(arr, 4)<<endl;
    return 0;
}