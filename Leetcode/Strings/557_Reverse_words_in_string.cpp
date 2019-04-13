// Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
// 
// Example 1:
// Input: "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"

// Soultion 1

class Solution {
public:
    string reverseStr(char* token)
    {
        string str(token);
        string rev = "";
        for(int i=0; i<str.size(); i++)
        {
            rev += str[str.size()-1-i];
        }
        return rev;
    }
    
    string reverseWords(string s) {
        string retStr = "";
        char* schar = new char[s.length() + 1];
        strcpy(schar, s.c_str());
        
        char* token = strtok(schar, " ");
        while(token != NULL)
        {
            retStr += reverseStr(token);
            retStr += " ";
            token = strtok(NULL, " ");
        }
        retStr.pop_back();

        delete schar;
        return retStr;
    }
};

// Solution 2

class Solution {
public:
    string revWord(string subWord)
    {
        string rev;
        for(int i=0; i<subWord.size(); i++)
        {
            rev += subWord[subWord.size() - 1 -i];
        }
        return rev;
    }
    
    string reverseWords(string s) {
        string ret;
        string subWord;
        
        for(int i=0; i<s.size(); i++)
        {
            if(s[i] == ' ')
            {
                ret += revWord(subWord);
                ret += ' ';
                subWord = "";
            } 
            else
                subWord += s[i];
        }
        ret += revWord(subWord);
        return ret;
    }
};