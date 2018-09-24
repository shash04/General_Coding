/////////////////////////////////////////////////////////////////////////
// Solution 1:  crude approach
// for each char in string, change case of each other char and make 
// strings.
// Problem: doesn't cover case where multiple chars need change case
/////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void changeCase(string &str, int i){
        if(islower(str[i]))
            str.replace(i, 1, 1, toupper(str[i]));
        else
            str.replace(i, 1, 1, tolower(str[i]));
    }
    
    vector<string> letterCasePermutation(string S) {
        vector<string> v1;
        string strCopy = S;
        
        v1.push_back(S);
        
        for(int i=0; i<S.size(); i++){
            strCopy = S;
            
            if(isdigit(S[i]))
                continue;
            
            changeCase(strCopy, i);
            v1.push_back(strCopy);
            
            for(int j = i+1; j < S.size() && i != S.size() - 1; j++)
            {
                if(isdigit(strCopy[j]))
                continue;
                
                changeCase(strCopy, j);
                v1.push_back(strCopy);
            }
        }
        return v1;
    }
};

/////////////////////////////////////////////////////////////////////////
// Solution 2:  using binary number approach
// for each case one (first) bit toggles every time, second bit 
// toggles after two iterations, third bit toggles every 4th iteration...
// Problem: in between numbers spoil the indexing in for loops
/////////////////////////////////////////////////////////////////////////

class Solution {
public:
    void changeCase(string &str, int i){
        if(islower(str[i]))
            str.replace(i, 1, 1, toupper(str[i]));
        else
            str.replace(i, 1, 1, tolower(str[i]));
    }
       
    vector<string> letterCasePermutation(string S) {
        vector<string> v1;
        string strCopy = S;
        
        int countChars = getTotalAlphabets(S);
        int numStrings = pow(2, countChars);
        
        transform(S.begin(), S.end(), S.begin(), ::tolower);
        for(int j=0; j<numStrings; j++)
        {
            if(j % 2)
                changeCase(S, 0);
            for(int i=1; i<S.size(); i++)
            {
                if(isdigit(S[i]))
                    continue;

                int factor = pow(2, i);
                
                if((j/factor) % factor)
                    changeCase(S, i);
            }
            v1.push_back(S);
        }
        return v1;
    }
};

/////////////////////////////////////////////////////////////////////////
// Actual solution using backtracking algo
/////////////////////////////////////////////////////////////////////////

class Solution {
    void backtrack(string &s, int i, vector<string> &res) {
        if (i == s.size()) {
            res.push_back(s);
            return;
        }
        backtrack(s, i + 1, res);
        if (isalpha(s[i])) {
            // toggle case
            s[i] ^= (1 << 5);
            backtrack(s, i + 1, res);
            // return previous case
            s[i] ^= (1 << 5);
        }
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> res;
        backtrack(S, 0, res);
        return res;
    }
};