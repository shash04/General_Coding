// Example 1:
// Input: 
// ["9001 discuss.leetcode.com"]
// Output: 
// ["9001 discuss.leetcode.com", "9001 leetcode.com", "9001 com"]
// Explanation: 
// We only have one website domain: "discuss.leetcode.com". As discussed above, the subdomain "leetcode.com" and "com" will also be visited. So they will all be visited 9001 times.

// Example 2:
// Input: 
// ["900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"]
// Output: 
// ["901 mail.com","50 yahoo.com","900 google.mail.com","5 wiki.org","5 org","1 intel.mail.com","951 com"]
// Explanation: 
// We will visit "google.mail.com" 900 times, "yahoo.com" 50 times, "intel.mail.com" once and "wiki.org" 5 times.
// For the subdomains, we will visit "mail.com" 900 + 1 = 901 times, "com" 900 + 50 + 1 = 951 times, and "org" 5 times.

// https://leetcode.com/problems/subdomain-visit-count/

class Solution {
public:
    void updateDomain(map<string, int> &domainMap, const string &dom, const int &count)
    {
        if(domainMap.find(dom) != domainMap.end())
        {
            domainMap[dom] += count;
        }
        else
        {
            domainMap[dom] = count;
        }
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> domainMap;
        vector<string> retVec;
        for(int i=0; i<cpdomains.size(); i++)
        {
            string entry = cpdomains[i];
            
            int pos_space = entry.find(" ");
            
            string countStr = entry.substr(0, pos_space);
            int count = stoi(countStr);
            
            string domain = entry.substr(pos_space+1);
            updateDomain(domainMap, domain, count);
            
            int pos_dot = domain.find(".");
            while(pos_dot != string::npos)
            {
                domain = domain.substr(pos_dot+1);
                updateDomain(domainMap, domain, count);
                pos_dot = domain.find(".");
            }
        }
        
        for(auto iter=domainMap.begin(); iter != domainMap.end(); iter++)
        {
            string str = to_string(iter->second) + " " + iter->first;
            retVec.push_back(str);
        }
        
        return retVec;
    }
};