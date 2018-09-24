class Solution {
public:
    string toLowerCase(string str) {
        string ret = "";      
        char low;
        
        for(int i=0; i<str.length(); i++)
        {
            if(str[i]>='A' && str[i]<='Z')
                low = str[i] - ('Z' - 'z');
            else
                low = str[i];
            ret += low;
        }
        return ret;
    }
};