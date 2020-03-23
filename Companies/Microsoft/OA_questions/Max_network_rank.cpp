// An infrastructure consisting of N cities, numbered from 1 to N, and M bidirectional roads between them is given.
// Roads do not intersect apart from at their start and end points (they can pass through underground tunnels to avoid collisions).
// For each pair of cities directly connected by a road, let's define their network rank as the total number of roads that are
// connected to either of the two cities.

// Write a function:
// class Solution { public int solution (int[] a, intu B, int n); }

// that, given two arrays A, B consisting of Mintegers each and an integer N, where A[U] and Blü are cities at the two ends
// of the i-th road, returns the maximal network rank in the whole infrastructure.

// Examples:
// 1. Given A = [1, 2, 3, 3), B = [2, 3, 1, 41 and N = 4, the function should return 4.
// The chosen cities may be 2 and 3, and the four roads connected to them are: (2, 1), (2,3), (3, 1), (3, 4).

// https://leetcode.com/discuss/interview-question/364760/

int getNetworkRank(vector<int> A, vector<int> B, int N)
{
    vector<int> edges(N+1, 0);
    int maxRank = -1;
    
    for(int i=0; i < A.size(); i++)
    {
        edges[A[i] - 1]++;
        edges[B[i] - 1]++;
    }
    
    for(int i=0; i < A.size(); i++)
    {
        int currRank = edges[A[i] - 1] + edges[B[i] - 1] - 1;           // -1 : to avoid counting same connection again
        maxRank = max(maxRank, currRank);
    }
    
    return maxRank;
}

int main()
{
    vector<int> A = {1,2,3,3};
    vector<int> B = {2,3,1,4};
    cout<<"Max Network Rank = "<<getNetworkRank(A, B, 4)<<endl;
}