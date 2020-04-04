class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<bitset<26>> bitsArr;
        int maxLen = 0;
        int maxStrSize = 0;
        
        for(string& s : arr)
        {
            bitset<26> bs;
            
            // Populate current bitset vec
            for(char& c : s)
                bs.set(c - 'a');
            
            // If all the chars are unique, add to bitsArr
            if(bs.count() == s.size())
            {
                bitsArr.push_back(bs);
                maxStrSize = max(maxStrSize, (int)s.size());
            }
        }
        
        maxLen = maxLenHelper(bitsArr, bitset<26>(), 0);
        
        if(maxStrSize == maxLen)
            return 0;
        
        return maxLen;
    }
    
    int maxLenHelper(vector<bitset<26>>& bitsArr, bitset<26> bs, int start)
    {
        int currMaxLen = bs.count();
        
        for(int i=start; i < bitsArr.size(); i++)
        {
            // Check if add the two strings would have all unique chars 
            if((bitsArr[i] & bs).none())
            {
                currMaxLen = max(currMaxLen, maxLenHelper(bitsArr, bitsArr[i] | bs, i+1));
            }
        }
        
        return currMaxLen;
    }
};

int main() {
    Solution s;
    vector<string> v1 = {"co","dil","ity"};
    vector<string> v2 = {"abc","kkk","def","csv"};
    vector<string> v3 = {"abc","ade","akl"};
    cout<<s.maxLength(v1)<<endl;
    cout<<s.maxLength(v2)<<endl;
    cout<<s.maxLength(v3)<<endl;
}