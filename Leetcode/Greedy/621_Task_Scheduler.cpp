// Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task.
// Tasks could be done in any order. Each task is done in one unit of time. For each unit of time,
// the CPU could complete either one task or just be idle.

// However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array),
// that is that there must be at least n units of time between any two same tasks.

// Return the least number of units of times that the CPU will take to finish all the given tasks.

// Example 1:
// Input: tasks = ["A","A","A","B","B","B"], n = 2
// Output: 8
// Explanation: 
// A -> B -> idle -> A -> B -> idle -> A -> B
// There is at least 2 units of time between any two same tasks.

// Example 2:
// Input: tasks = ["A","A","A","B","B","B"], n = 0
// Output: 6
// Explanation: On this case any permutation of size 6 would work since n = 0.
// ["A","A","A","B","B","B"]
// ["A","B","A","B","A","B"]
// ["B","B","B","A","A","A"]
// ...
// And so on.

// Example 3:
// Input: tasks = ["A","A","A","A","A","A","B","C","D","E","F","G"], n = 2
// Output: 16
// Explanation: 
// One possible solution is
// A -> B -> C -> A -> D -> E -> A -> F -> G -> A -> idle -> idle -> A -> idle -> idle -> A
 

// Constraints:
// 1 <= task.length <= 104
// tasks[i] is upper-case English letter.
// The integer n is in the range [0, 100].

// https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int maxFreq = 0;
        
        vector<int> charFreq (26, 0);
        
        int maxFreqUnits = 0;
        int numTasks = 0;
        
        for(char& c : tasks)
        {
            charFreq[c - 'A']++;
            maxFreq = max(maxFreq, charFreq[c - 'A']);
        }
        
        // Time needed to finish max freq task = (cooling time + one unit to actually complete task) * (maxFreq - 1)
        // NOTE - the above calculation leaves out last unit time to schedule last maxFreq task
        // It is added in next step
        maxFreqUnits = (n + 1) * (maxFreq - 1);
        
        // Consider following example - A A A B B B and cooling period = 2
        // Queue to only schedule A - [A * * A * * A]
        // Queue to schedule A and B - [A B * A B * A B]
        // The idea is to first consider only idle slots to fill maxFreq task
        // Second step ensures to add the last busy slots required for all maxFreq tasks
        for(int i = 0; i < 26; i++)
        {
            if(maxFreq == charFreq[i])
                maxFreqUnits++;
            
            if(charFreq[i] > 0)
                numTasks += charFreq[i];
        }
        
        // Return max of maxFreqUnits calculated and total number of tasks
        return max(maxFreqUnits, numTasks);
    }
};