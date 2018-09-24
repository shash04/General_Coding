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