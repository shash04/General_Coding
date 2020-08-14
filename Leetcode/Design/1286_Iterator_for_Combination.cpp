// Design an Iterator class, which has:

// A constructor that takes a string characters of sorted distinct lowercase English letters and a number combinationLength as arguments.
// A function next() that returns the next combination of length combinationLength in lexicographical order.
// A function hasNext() that returns True if and only if there exists a next combination.
 

// Example:

// CombinationIterator iterator = new CombinationIterator("abc", 2); // creates the iterator.

// iterator.next(); // returns "ab"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "ac"
// iterator.hasNext(); // returns true
// iterator.next(); // returns "bc"
// iterator.hasNext(); // returns false
 

// Constraints:
// 1 <= combinationLength <= characters.length <= 15
// There will be at most 10^4 function calls per test.
// It's guaranteed that all calls of the function next are valid.

// https://leetcode.com/problems/iterator-for-combination/

class CombinationIterator {
    queue<string> strQ;
    
    void getCombinations(string& s, queue<string>& strQ, string currStr, int idx, int len)
    {
        if(currStr.size() == len)
        {
            strQ.push(currStr);
            return;
        }
        
        if(idx > s.size())
            return;
        
        for(int i = idx; i < s.size(); i++)
        {
            currStr += s[i];
            getCombinations(s, strQ, currStr, i + 1, len);
            currStr.pop_back();
        }
    }
    
public:
    CombinationIterator(string characters, int combinationLength) {       
        getCombinations(characters, strQ, "", 0, combinationLength);
    }
    
    string next() {
        string retStr = strQ.front();
        strQ.pop();
        return retStr;
    }
    
    bool hasNext() {
        return !strQ.empty();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */