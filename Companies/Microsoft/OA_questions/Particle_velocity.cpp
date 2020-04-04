// You are a programmer in a scientific team doing research into particles. As an experiment, you have measured the position of a single particle
// in N equally distributed moments of time. The measurement made in moment K is recorded in array A as A[K].
// Now, your job is to count all the periods of time when the movement of the particle was stable. Those are the periods during which the particle
// doesn't change its velocity: .e. the difference between any two consecutive position measurements remains the same. Note that you need at least
// three measurements to be sure that the particle didn't change its velocity

// For example:
// 1, 3, 5, 7, 9 is stable (velocity is 2),
// 7, 7, 7, 7 is stable (particle stays in place) 3, -1, -5, -9 is stable (velocity is -4),
// 0, 1 is not stable (you need at least three measurements)
// 1, 1, 2, 5, i is not stable (velocity changes between measurements)

// More formally, your task is to find all the periods of time A[Pl. A[P+1). .... A[Q(of length at least 3) during which the movement of the particle
// is stable. Note that some periods of time might be contained in others (see example test).

// Write a function:
// int solution (vector<int> &A);
// that, given array A consisting of N integers representing the results of the measurements, returns the number of periods of time when the movement
// of the particle was stable. The function should return -1 if the result exceeds 1,000,000,000.

// Given array A = (-1,1,3,3,3,2,3, 2, 1, 0) the function should return 5, because there are five periods during which the movement of the particle
// is stable, namely: (0,2), (2,4), (6,9), (6,8) and (7,9).
// Note that the last two periods are contained by (6,9).

// https://leetcode.com/discuss/interview-question/428272/

// https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int sliceCnt = 0;
        int currSum = 0;
        
        vector<int> dp (A.size(), 0);
        
        for(int i = 2; i < A.size(); i++)
        {
            if( (A[i] - A[i-1]) == (A[i-1] - A[i-2]) )
            {
                currSum += 1;
                sliceCnt += currSum;
            }
            else
            {
                currSum = 0;
            }
        }
        
        return sliceCnt;
    }
};