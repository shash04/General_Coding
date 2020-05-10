// Suppose you are at a party with n people (labeled from 0 to n - 1) and among them, there may exist one celebrity.
// The definition of a celebrity is that all the other n - 1 people know him/her but he/she does not know any of them.

// Now you want to find out who the celebrity is or verify that there is not one. The only thing you are allowed to do is to
// ask questions like: "Hi, A. Do you know B?" to get information of whether A knows B. You need to find out the celebrity
// (or verify there is not one) by asking as few questions as possible (in the asymptotic sense).

// You are given a helper function bool knows(a, b) which tells you whether A knows B. Implement a function int findCelebrity(n).
// There will be exactly one celebrity if he/she is in the party. Return the celebrity's label if there is a celebrity in the party.
// If there is no celebrity, return -1.

// Example 1:
// Input: graph = [
//   [1,1,0],
//   [0,1,0],
//   [1,1,1]
// ]
// Output: 1
// Explanation: There are three persons labeled with 0, 1 and 2. graph[i][j] = 1 means person i knows person j,
// otherwise graph[i][j] = 0 means person i does not know person j.
// The celebrity is the person labeled as 1 because both 0 and 2 know him but 1 does not know anybody.

// Example 2:
// Input: graph = [
//   [1,0,1],
//   [1,1,0],
//   [0,1,1]
// ]

// Output: -1
// Explanation: There is no celebrity.

// Note:
// The directed graph is represented as an adjacency matrix, which is an n x n matrix where a[i][j] = 1
// means person i knows person j while a[i][j] = 0 means the contrary.
// Remember that you won't have direct access to the adjacency matrix.

// https://leetcode.com/problems/find-the-celebrity/

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int currCelebrity = 0;
        
        // First iteration to find probable celebrity
        for(int i=0; i < n; i++)
        {
            if(knows(currCelebrity, i))
                currCelebrity = i;
        }
        
        // Second iteration to verify probabe celebrity satisfies all conditions
        for(int i=0; i < n; i++)
        {
            if(i == currCelebrity)
                continue;
            
            // Celebrity shouldn't know anyone else and everyone should know celebrity
            // Return -1 if this isn't true
            if(knows(currCelebrity, i) || !knows(i, currCelebrity))
                return -1;
        }
        
        return currCelebrity;
    }
};

// ***************************************************************************************************
// Follow up interview question to store the results of API call in cache
// The result of API calls in first iteration can be used in second iteration to optimize run time
// Earlier the probable candidate is found in first iteration, more repetative calls in second iter
// ***************************************************************************************************

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
private:
    map<pair<int, int>, bool> cache;

    // ***** Override knows API for storing the results in cache *****   
    bool knowsCache(int a, int b)
    {
        if(!cache.count({a, b}))
            cache[{a, b}] = knows(a, b);
        
        return cache[{a, b}];
    }
    
public:    
    int findCelebrity(int n) {
        int currCelebrity = 0;
        
        // First iteration to find probable celebrity
        for(int i=0; i < n; i++)
        {
            if(knowsCache(currCelebrity, i))
                currCelebrity = i;
        }
        
        // Second iteration to verify probabe celebrity satisfies all conditions
        for(int i=0; i < n; i++)
        {
            if(i == currCelebrity)
                continue;
            
            // Celebrity shouldn't know anyone else and everyone should know celebrity
            // Return -1 if this isn't true
            if(knowsCache(currCelebrity, i) || !knowsCache(i, currCelebrity))
                return -1;
        }
        
        return currCelebrity;
    }
};
