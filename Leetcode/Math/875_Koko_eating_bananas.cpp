// Koko loves to eat bananas.  There are N piles of bananas, the i-th pile has piles[i] bananas.
// The guards have gone and will come back in H hours.

// Koko can decide her bananas-per-hour eating speed of K.  Each hour, she chooses some pile of bananas, and eats K bananas from that pile.
// If the pile has less than K bananas, she eats all of them instead, and won't eat any more bananas during this hour.

// Koko likes to eat slowly, but still wants to finish eating all the bananas before the guards come back.

// Return the minimum integer K such that she can eat all the bananas within H hours.

// Example 1:
// Input: piles = [3,6,7,11], H = 8
// Output: 4

// Example 2:
// Input: piles = [30,11,23,4,20], H = 5
// Output: 30

// Example 3:
// Input: piles = [30,11,23,4,20], H = 6
// Output: 23
 
// Constraints:
// 1 <= piles.length <= 10^4
// piles.length <= H <= 10^9
// 1 <= piles[i] <= 10^9

// https://leetcode.com/problems/koko-eating-bananas/

class Solution {
    bool isPossible(vector<int>& piles, int K, int H)
    {
        int time = 0;
        
        for(int& bananas : piles)
            time += (bananas - 1) / K + 1;      // = ceil(bananas / K)
        
        return time <= H;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        // low = min bananas to eat in 1 H
        // high = max bananas to eat in 1 H - initialized to eating max bananas in 1 pile in 1 H
        int low = 1;
        int high = pow(10, 9);
        
        // Do binary search to find K = lowest value for which isPossible() return true
        while(low < high)
        {
            int mid = low + (high - low) / 2;
            
            // check if for mid value (K), is it possible to finish all piles in H hours
            if(isPossible(piles, mid, H))
                high = mid;
            else
                low = mid + 1;
        }
        
        return low;
    }
};
