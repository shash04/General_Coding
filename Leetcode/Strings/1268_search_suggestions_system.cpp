// Given an array of strings products and a string searchWord. We want to design a system that suggests at
// most three product names from products after each character of searchWord is typed. Suggested products
// should have common prefix with the searchWord. If there are more than three products with a common
// prefix return the three lexicographically minimums products.

// Return list of lists of the suggested products after each character of searchWord is typed. 

// Example 1:
// Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
// Output: [
// ["mobile","moneypot","monitor"],
// ["mobile","moneypot","monitor"],
// ["mouse","mousepad"],
// ["mouse","mousepad"],
// ["mouse","mousepad"]
// ]
// Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"]
// After typing m and mo all products match and we show user ["mobile","moneypot","monitor"]
// After typing mou, mous and mouse the system suggests ["mouse","mousepad"]

// Example 2:
// Input: products = ["havana"], searchWord = "havana"
// Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]

// Example 3:
// Input: products = ["bags","baggage","banner","box","cloths"], searchWord = "bags"
// Output: [["baggage","bags","banner"],["baggage","bags","banner"],["baggage","bags"],["bags"]]

// Example 4:
// Input: products = ["havana"], searchWord = "tatiana"
// Output: [[],[],[],[],[],[],[]]

// Constraints:
// 1 <= products.length <= 1000
// There are no repeated elements in products.
// 1 <= Σ products[i].length <= 2 * 10^4
// All characters of products[i] are lower-case English letters.
// 1 <= searchWord.length <= 1000
// All characters of searchWord are lower-case English letters.

// https://leetcode.com/problems/search-suggestions-system/

// *****************************************************************************************************
// Less intuitive but lot Faster solution
// *****************************************************************************************************
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> retVec (searchWord.size());
        
        if(products.size() == 0 || searchWord.size() == 0)
            return retVec;
        
        // Sort products
        sort(products.begin(), products.end());
        
        for(int i = 0; i < products.size(); i++)
        {
            // For each product check, add product to all searchWord substrs
            // till prefix matches and size of vec for prefix is not 3
            for(int j = 0; j < searchWord.size(); j++)
            {
                if(products[i][j] == searchWord[j])
                {
                    if(retVec[j].size() < 3)
                        retVec[j].push_back(products[i]);
                }
                else
                {
                    break;
                }
            }
        }
        
        return retVec;
    }
};

// *****************************************************************************************************
// More intuitive but Slower solution
// *****************************************************************************************************
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> retVec;
        
        if(products.size() == 0 || searchWord.size() == 0)
            return retVec;
        
        unordered_map<string, vector<string>> searchMap;
        
        // Populate Search map
        for(auto product : products)
        {
            string key = "";
            
            for(int i=0; i<product.size(); i++)
            {
                key += product[i];
                searchMap[key].push_back(product);
            }
        }
        
        // Sort each search vec lexicographically
        for(auto& entry : searchMap)
        {
            vector<string>& vec = entry.second;
            sort(vec.begin(), vec.end());
        }
        
        // Populate ans
        string searchStr = "";
        for(auto eachChar : searchWord)
        {
            searchStr += eachChar;
            vector<string> currVec;
            
            for(int i=0; i<3 && i<searchMap[searchStr].size(); i++)
            {
                if(searchMap.find(searchStr) != searchMap.end())
                    currVec.push_back(searchMap[searchStr][i]);
            }
                                      
            retVec.push_back(currVec);
        }
        
        return retVec;
    }
};