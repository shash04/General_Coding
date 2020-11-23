// Given a string s and an int k, return all unique substrings of s of size k with k distinct characters.

// Example 1:
// Input: s = "abcabc", k = 3
// Output: ["abc", "bca", "cab"]

// Example 2:
// Input: s = "abacab", k = 3
// Output: ["bac", "cab"]

// Example 3:
// Input: s = "awaglknagawunagwkwagl", k = 4
// Output: ["wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag"]
// Explanation: 
// Substrings in order are: "wagl", "aglk", "glkn", "lkna", "knag", "gawu", "awun", "wuna", "unag", "nagw", "agwk", "kwag", "wagl" 
// "wagl" is repeated twice, but is included in the output once.

// Constraints:
// The input string consists of only lowercase English letters [a-z]
// 0 ≤ k ≤ 26

// https://leetcode.com/discuss/interview-question/370112/

vector<string> getUniqueSubstr(const string& s, int k)
{
    unordered_set<string> result;
    unordered_map<char, int> freqMap;
    int idx = 0;
    int low = 0;
    
    while(idx < s.size())
    {
        freqMap[s[idx]]++;
        
        // As soon as the window has duplicate, slide the starting index of window
        while(freqMap[s[idx]] > 1 && low < s.size())
        {
            freqMap[s[low]]--;
            low++;
        }
        
        // If current window is inserted in the result, increment the starting idx and update map
        if(idx - low + 1 == k)
        {
            result.insert(s.substr(low, k));
            freqMap[s[low]]--;
            low++;
        }
        
        idx++;
    }
    
    return vector<string>(result.begin(), result.end());
}

void printResult(vector<string>& result)
{
    for(string& s : result)
        cout<<s<<", ";
    cout<<endl;
}

int main() {
    string s1 = "abcabc";
    string s2 = "awaglknagawunagwkwagl";
    vector<string> result = getUniqueSubstr(s2, 4);
    printResult(result);
}