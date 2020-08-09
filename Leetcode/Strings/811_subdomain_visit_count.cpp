// Example 1:
// Input: 
// ["9001 discuss.leetcode.com"]
// Output: 
// ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
// Explanation: 
// We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com"
// and "com" will also be visited. So they will all be visited 9001 times.

// Example 2:
// Input: 
// ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
// Output: 
// ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
// Explanation: 
// We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times.
// we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

// https://leetcode.com/problems/subdomain-visit-count/

// *********************************************************************************************
// Using substr approach - Faster
// *********************************************************************************************
class Solution {
    unordered_map<string, int> m1;
    
    void updateMap(string& s)
    {
        int pos = s.find(' ');
        int count = stoi(s.substr(0, pos));
        string domain = s.substr(pos + 1);
        
        m1[domain] += count;
        
        pos = domain.find('.');
        
        while(pos != string::npos)
        {
            domain = domain.substr(pos + 1);
            m1[domain] += count;
            pos = domain.find('.');
        }
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> retVec;
        
        for(string& s : cpdomains)
        {
            updateMap(s);
        }
        
        for(auto& entry : m1)
        {
            string tmp = to_string(entry.second) + " " + entry.first;
            retVec.push_back(tmp);
        }
        
        return retVec;
    }
};

// *********************************************************************************************
// Using stringstream approach
// *********************************************************************************************
class Solution {
    unordered_map<string, int> m1;
    
    void updateMap(string& s)
    {
        stringstream ss(s);
        string currStr;
        vector<string> v1;
        
        while(ss >> currStr)
        {
            stringstream split(currStr);
            string word;
            
            if(v1.empty())
            {
                v1.push_back(currStr);
                continue;
            }
            
            while(getline(split, word, '.'))
            {
                v1.push_back(word);
            }
            
            string tmp;
            
            for(int i = v1.size() - 1; i >= 1; i--)
            {
                tmp = v1[i] + tmp;
                m1[tmp] += stoi(v1[0]);
                tmp = '.' + tmp; 
            }
        }
    }
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> retVec;
        
        for(string& s : cpdomains)
        {
            updateMap(s);
        }
        
        for(auto& entry : m1)
        {
            string tmp = to_string(entry.second) + " " + entry.first;
            retVec.push_back(tmp);
        }
        
        return retVec;
    }
};
