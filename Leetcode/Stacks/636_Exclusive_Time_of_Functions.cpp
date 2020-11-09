// On a single-threaded CPU, we execute a program containing n functions. Each function has a unique ID between 0 and n-1.

// Function calls are stored in a call stack: when a function call starts, its ID is pushed onto the stack, and when a function call ends,
// its ID is popped off the stack. The function whose ID is at the top of the stack is the current function being executed.
// Each time a function starts or ends, we write a log with the ID, whether it started or ended, and the timestamp.

// You are given a list logs, where logs[i] represents the ith log message formatted as a string "{function_id}:{"start" | "end"}:{timestamp}".
// For example, "0:start:3" means a function call with function ID 0 started at the beginning of timestamp 3, and "1:end:2" means a function call
// with function ID 1 ended at the end of timestamp 2. Note that a function can be called multiple times, possibly recursively.

// A function's exclusive time is the sum of execution times for all function calls in the program. For example,
// if a function is called twice, one call executing for 2 time units and another call executing for 1 time unit,
// the exclusive time is 2 + 1 = 3.

// Return the exclusive time of each function in an array, where the value at the ith index represents the exclusive time for the function with ID i.

// Example 1:
// Input: n = 2, logs = ["0:start:0","1:start:2","1:end:5","0:end:6"]
// Output: [3,4]

// Explanation:
// Function 0 starts at the beginning of time 0, then it executes 2 for units of time and reaches the end of time 1.
// Function 1 starts at the beginning of time 2, executes for 4 units of time, and ends at the end of time 5.
// Function 0 resumes execution at the beginning of time 6 and executes for 1 unit of time.
// So function 0 spends 2 + 1 = 3 units of total time executing, and function 1 spends 4 units of total time executing.

// https://leetcode.com/problems/exclusive-time-of-functions/

class Solution {    
    vector<int> splitLog(const string& log)
    {
        istringstream ss(log);
        string word;
        
        vector<int> logVec;
        int i = 0;
        
        while(getline(ss, word, ':'))
        {
            if(i == 1)
            {
                if(word == "start")
                    logVec.push_back(1);
                else
                    logVec.push_back(-1);
            }
            else
            {
                logVec.push_back(stoi(word));
            }
            i++;
        }
        
        return logVec;
    }
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<vector<int>> s1;
        vector<int> result (n, 0);
        
        for(string& log : logs)
        {            
            vector<int> curFunc = splitLog(log);

            // start of the function call
            if(curFunc[1] == 1)
            {
                if(!s1.empty())
                {
                    // Update the prev function time as it is now stalled
                    vector<int> prevFunc = s1.top();
                    result[prevFunc[0]] += curFunc[2] - prevFunc[2];
                }
                
                s1.push(curFunc);
            }
            // end of function call. Pop from stack and add time
            else
            {
                vector<int> prevFunc = s1.top();
                result[prevFunc[0]] += curFunc[2] - prevFunc[2] + 1;
                
                s1.pop();
                
                if(!s1.empty())
                {
                    // update the start time of top of the stack to current timestamp
                    vector<int>& newTop = s1.top();
                    newTop[2] = curFunc[2] + 1;
                }
            }
        }
        
        return result;
    }
};