// Given an input string, reverse the string word by word.

// Example 1:
// Input: "the sky is blue"
// Output: "blue is sky the"

// Example 2:
// Input: "  hello world!  "
// Output: "world! hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.

// Example 3:
// Input: "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.

// https://leetcode.com/problems/reverse-words-in-a-string/


// Solution 1 - Takes lot of space as compared to solution 2
class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string word;
        string revString = "";
        
        while(ss>>word)
        {
            if(revString.size() == 0)
                revString += word;
            else
                revString = word + " " + revString;
        }
        
        return revString;
    }
};

// Solution 2 - Space efficient
class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)
            return s;
        
        string retStr;
        istringstream ss(s);
        
        string currWord;
        vector<string> wordVec;
        
        int i=0;
        
        // Remove trailing spaces
        while(s[i] == ' ' && i < s.size())
            i++;
        
        // Store words in wordVec
        for(; i < s.size(); i++)
        {
            // Check for currWord size
            if(s[i] == ' ' && currWord.size() != 0)
            {
                wordVec.push_back(currWord);
                currWord.clear();
                continue;
            }
            
            // Dont add spaces
            if(s[i] != ' ')
                currWord += s[i];
        }
        
        // Add if last word was valid
        if(currWord.size() != 0)
        {
            wordVec.push_back(currWord);
        }
        
        for(int i=wordVec.size() - 1; i >= 0; i--)
        {
            retStr += wordVec[i] + " ";
        }
        
        retStr = retStr.substr(0, retStr.size() - 1);
        
        return retStr;
    }
};

// Solution 3
class Solution {
public:
    string reverseWords(string s) {
        string revString;
        string word;
        
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] != ' ')
                word += s[i];
            else
            {
                if(revString.length() == 0)
                    revString += word;
                else
                    revString = word + " " + revString;

                word = "";

                while(s[i+1] == ' ' && i+1<s.length())
                    i++;
            }
        }

        if(word != "" && revString != "")
            word += " ";

        revString = word + revString;

        return revString;
    }
};