// Implement FreqStack, a class which simulates the operation of a stack-like data structure.
// FreqStack has two functions:
// push(int x), which pushes an integer x onto the stack.
// pop(), which removes and returns the most frequent element in the stack.
// If there is a tie for most frequent element, the element closest to the top of the stack is removed and returned.
 
// Example 1:
// Input: 
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],
// [[],[5],[7],[5],[7],[4],[5],[],[],[],[]]
// Output: [null,null,null,null,null,null,null,5,7,5,4]

// Explanation:
// After making six .push operations, the stack is [5,7,5,7,4,5] from bottom to top.  Then:
// pop() -> returns 5, as 5 is the most frequent.
// The stack becomes [5,7,5,7,4].

// pop() -> returns 7, as 5 and 7 is the most frequent, but 7 is closest to the top.
// The stack becomes [5,7,5,4].

// pop() -> returns 5.
// The stack becomes [5,7,4].

// pop() -> returns 4.
// The stack becomes [5,7].

// https://leetcode.com/problems/maximum-frequency-stack/

class FreqStack {
public:
    unordered_map<int, stack<int>> m1;
    unordered_map<int, int> frequency;
    int maxFrequency;
    
    FreqStack() {
        maxFrequency = 0;
    }
    
    void push(int x) {
        frequency[x]++;
        m1[frequency[x]].push(x);
        maxFrequency = max(maxFrequency, frequency[x]);
    }
    
    int pop() {
        int ret = m1[maxFrequency].top();
        m1[maxFrequency].pop();
        if(m1[maxFrequency].empty())
            maxFrequency--;
        frequency[ret]--;
        return ret;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */