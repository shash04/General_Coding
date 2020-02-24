// Given a sequence of matrices, find the most efficient way to multiply these matrices together.
// The problem is not actually to perform the multiplications, but merely to decide in which order to perform the multiplications.

// We have many options to multiply a chain of matrices because matrix multiplication is associative. In other words,
// no matter how we parenthesize the product, the result will be the same. For e.g. if we had four matrices A, B, C, and D:

// (ABC)D = (AB)(CD) = A(BCD) = ....

// However, the order in which we parenthesize the product affects the number of simple arithmetic operations needed to compute
// the product, or the efficiency. For example, suppose A is a 10 × 30 matrix, B is a 30 × 5 matrix, and C is a 5 × 60 matrix. Then,

//     (AB)C = (10×30×5) + (10×5×60) = 1500 + 3000 = 4500 operations
//     A(BC) = (30×5×60) + (10×30×60) = 9000 + 18000 = 27000 operations.

// Clearly the first parenthesization requires less number of operations.

// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/

// https://www.youtube.com/watch?v=vgLJZMUfnsU&list=PLrmLmBdmIlpsHaNTPP_jHHDx_os9ItYXr&index=3
// https://www.youtube.com/watch?v=prx1psByp7U

#include <iostream>
#include <vector>
using namespace std;

class MatrixMultiplication{
public:
    int minimumCostMatMul(vector<int>& arr)
    {
        int n = arr.size();
        vector<vector<int>> dp (n, vector<int>(n, 0));
        int currCost = 0;
        
        // Vary the length of chain from 2 to n-1
        for(int L = 2; L < n; L++)
        {
            for(int i=0; i < n - L; i++)
            {
                int j = i + L;                                                  // Note: First column is never used
                dp[i][j] = 10000000;                                            // Could also be INT_MAX
                
                for(int k = i+1; k < j; k++)
                {
                    currCost = dp[i][k] + dp[k][j] + arr[i] * arr[k] * arr[j];
                    
                    if( currCost < dp[i][j] )
                        dp[i][j] = currCost;
                }
            }
        }
        
        return dp[0][n-1];
    }
};

int main() {
	MatrixMultiplication mmObj;
	vector<int> arr = { 2, 3, 6, 4, 5 };
	int minCost = mmObj.minimumCostMatMul(arr);
	cout<<minCost<<endl;
	return 0;
}