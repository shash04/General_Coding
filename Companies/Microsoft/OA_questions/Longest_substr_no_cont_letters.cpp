// Given a string s containing only a and b, find longest substring of s such that s does not contain more than two contiguous occurrences of a and b.

// Example 1:
// Input: "aabbaaaaabb"
// Output: "aabbaa"

// Example 2:
// Input: "aabbaabbaabbaa"
// Output: "aabbaabbaabbaa"

// https://leetcode.com/discuss/interview-question/398031/

string longestStr(string& s)
{
    if(s.size() <= 2)
        return s;
    
    string retStr;
    char currChar = s[0];
    int count = 0;
    int k = 0;
    
    while(k < s.size())
    {
        while(k < s.size() && currChar == s[k])
        {
            count++;
            k++;
        }
        
        for(int i=0; i < count && i < 2; i++)
        {
            retStr += currChar;
        }
        
        // Update curr char and count
        currChar = s[k];
        count = 0;
    }
    
    return retStr;
}

int main() {
    string s = "aabbaaaaabb";
    cout<<longestStr(s)<<endl;
}