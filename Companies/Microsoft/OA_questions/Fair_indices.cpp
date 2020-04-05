// You are given two arrays A and B consisting of N integers each.
// Index K is named fair if the four sums
// (A[O] + ... + A[K-1]),
// (A[K] + ... + A[N-1]),
// (B[0] + ... + B[K-1]) and
// (B[K] + ... + B[N-1)) are all equal.

// In other words, K is the index where the two arrays, A and B, can be split into two non-empty arrays each)
// in such a way that the sums of the resulting arrays' elements are equal.
// For example, given arrays A = [4,-1,0,3] and B = (-2,5, 0, 3), index K = 2 is fair. The sums of the subarrays
// are all equal: 4+ (-1) = 3; 0+3 = 3:-2 + 5 = 3 and 0 + 3 = 3. On the other hand, index K = 1 is not fair,
// the sums of the subarrays are: 4:(-1) + 0 + 3 = 2;-2 and 5+0+ 3 = 8.

// Write a function:
// int solution (vector<int> &A, vector int> &B);
// which, given two arrays of integers A and B, returns the number of fair indexes.

// Examples:
// 1. Given A = [4,-1,0,3] and B = (-2,5, 0, 3), your function should return 2.
// The fair indexes are 2 and 3. In both cases, the sums of elements of the subarrays are equal to 3.

// 2. Given A = [2,-2, -3,3] and B = [0, 0, 4,-4], your function should return 1. The only fair index is 2.
// Index 4 is not fair as the subarrays containing indexes from K to N-1 would be empty.

// 3. Given A = [4,-1, 0,3] and B = (-2, 6,0,4), your function should return 0. There are no fair indexes.

// 4. Given A = [3, 2, 6] and B = [4,1, 6), your function should return 0.

// 5. Given A = [1,4, 2,-2,5), B = [7,-2, -2, 2, 5), your function should return 2. The fair indexes are 2 and 4.

// Write an efficient algorithm for the following assumptions:
// - N is an integer within the range [2..100.000]
// - each element of arrays A, B is an integer within the range [-1,000,000,000..1,000,000,000].

// Assuming both arrA and arrB have same sizes
int numFairIndices(const vector<int>& arrA, const vector<int>& arrB)
{
    int numFairIndices = 0;
    int totalSumA = 0;
    int totalSumB = 0;
    
    for(int i=0; i < arrA.size(); i++)
    {
        totalSumA += arrA[i];
        totalSumB += arrB[i];
    }
    
    if(totalSumA != totalSumB)
        return 0;
    
    int sumA = 0, sumB = 0;
    for(int i=0; i < arrA.size() - 1; i++)
    {
        sumA += arrA[i];
        sumB += arrB[i];
        
        if((sumA == totalSumA - sumA) && (sumB == totalSumB - sumB) && (sumA == sumB))
            numFairIndices++;
    }
    return numFairIndices;
}

int main() {
    vector<int> arrA = {1,4,2,-2,5};
    vector<int> arrB = {7,-2,-2,2,5};
    
    cout << numFairIndices(arrA, arrB) << endl;
}
