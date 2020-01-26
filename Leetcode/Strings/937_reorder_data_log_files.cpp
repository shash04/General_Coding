// You have an array of logs.  Each log is a space delimited string of words.
// For each log, the first word in each log is an alphanumeric identifier.  Then, either:

// Each word after the identifier will consist only of lowercase letters, or;
// Each word after the identifier will consist only of digits.
// We will call these two varieties of logs letter-logs and digit-logs.
// It is guaranteed that each log has at least one word after its identifier.

// Reorder the logs so that all of the letter-logs come before any digit-log.
// The letter-logs are ordered lexicographically ignoring identifier, with the identifier used in case of ties.
// The digit-logs should be put in their original order.
// Return the final order of the logs.

// Example 1:
// Input: logs = ["dig1 8 1 5 1","let1 art can","dig2 3 6","let2 own kit dig","let3 art zero"]
// Output: ["let1 art can","let3 art zero","let2 own kit dig","dig1 8 1 5 1","dig2 3 6"]

// Constraints:
// 0 <= logs.length <= 100
// 3 <= logs[i].length <= 100
// logs[i] is guaranteed to have an identifier, and a word after the identifier.

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        if(logs.size() == 0)
            return logs;
        
        vector<string> letLogs, digLogs;
        
        for(auto str : logs)
        {
            for(int i=0; i<str.size()-1; i++)
            {
                if(str[i] == ' ')
                {
                    if((str[i+1] >= '0' && str[i+1] <= '9'))
                    {
                        digLogs.push_back(str);
                        break;
                    }
                    else
                    {
                        letLogs.push_back(str);
                        break;
                    }
                }
            }
        }
        
        sort(letLogs.begin(), letLogs.end(), sortLetterLogs);
        
        move(digLogs.begin(), digLogs.end(), back_inserter(letLogs));
        // letLogs.insert(letLogs.end(), digLogs.begin(), digLogs.end());
        
        return letLogs;
    }
    
    static bool sortLetterLogs(string& a, string& b)
    {
        int idx = 0;
        string aId, bId, aLog, bLog;
        
        for(int i=0; i<a.size(); i++)
        {
            if(a[i] == ' ') { idx = i; break; }
        }
        
        aId = a.substr(0, idx);
        aLog = a.substr(idx+1);
        
        for(int i=0; i<b.size(); i++)
        {
            if(b[i] == ' ') { idx = i; break; }
        }
        
        bId = b.substr(0, idx);
        bLog = b.substr(idx+1);
        
        if(aLog == bLog)
            return aId < bId;
        
        return aLog < bLog;
    }
};