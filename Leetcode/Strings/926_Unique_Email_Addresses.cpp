// If you add periods ('.') between some characters in the local name part of an email address,
// mail sent there will be forwarded to the same address without dots in the local name.
// For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.

// If you add a plus ('+') in the local name, everything after the first plus sign will be ignored.
// This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.

// It is possible to use both of these rules at the same time.  They do not apply for domain names.

// Given a list of emails, we send one email to each address in the list.  How many different addresses actually receive mails? 

// Example 1:
// Input: ["test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"]
// Output: 2
// Explanation: "testemail@leetcode.com" and "testemail@lee.tcode.com" actually receive mails

// https://leetcode.com/problems/unique-email-addresses/

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> ids;
        for(int i=0; i<emails.size(); i++)
        {
            string email = emails[i];
            int index = email.find("@");
            string local = email.substr(0,index);
            string domain = email.substr(index);
            string actual_email;
            
            for(int j=0; j<local.size(); j++)
            {
                if(local[j] == '+')
                    break;
                else if(local[j] != '.')
                    actual_email += local[j];                    
            }
            actual_email += domain;
            if(ids.find(actual_email) == ids.end())
            {
                ids.insert(actual_email);
            }
        }
        return ids.size();
    }
};