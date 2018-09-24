// Example 1:
// Input: ["flower","flow","flight"]
// Output: "fl"

// Example 2:
// Input: ["dog","racecar","car"]
// Output: ""
// Explanation: There is no common prefix among the input strings.

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ret = "";
        if(strs.size() == 0)
            return ret;
        
        ret = strs[0];
        for(int i=0; i<strs[0].size(); i++)
        {
            for(int j=1; j<strs.size(); j++)
            {
                if(strs[j][i] != ret[i])
                {
                    ret = strs[j].substr(0, i);
                    return ret;
                }
            }
        }
        return ret;
    }
};