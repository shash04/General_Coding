// Given the array favoriteCompanies where favoriteCompanies[i] is the list of favorites companies for the ith person (indexed from 0).

// Return the indices of people whose list of favorite companies is not a subset of any other list of favorites companies.
// You must return the indices in increasing order.


// Example 1:
// Input: favoriteCompanies = [["leetcode","google","facebook"],["google","microsoft"],["google","facebook"],["google"],["amazon"]]
// Output: [0,1,4] 
// Explanation: 
// Person with index=2 has favoriteCompanies[2]=["google","facebook"] which is a subset of
// favoriteCompanies[0]=["leetcode","google","facebook"] corresponding to the person with index 0. 

// Person with index=3 has favoriteCompanies[3]=["google"] which is a subset of
// favoriteCompanies[0]=["leetcode","google","facebook"] and favoriteCompanies[1]=["google","microsoft"].

// Other lists of favorite companies are not a subset of another list, therefore, the answer is [0,1,4].
// Example 2:
// Input: favoriteCompanies = [["leetcode","google","facebook"],["leetcode","amazon"],["facebook","google"]]
// Output: [0,1] 
// Explanation: In this case favoriteCompanies[2]=["facebook","google"] is a subset of
// favoriteCompanies[0]=["leetcode","google","facebook"], therefore, the answer is [0,1].

// Example 3:
// Input: favoriteCompanies = [["leetcode"],["google"],["facebook"],["amazon"]]
// Output: [0,1,2,3]
 

// Constraints:
// 1 <= favoriteCompanies.length <= 100
// 1 <= favoriteCompanies[i].length <= 500
// 1 <= favoriteCompanies[i][j].length <= 20
// All strings in favoriteCompanies[i] are distinct.
// All lists of favorite companies are distinct, that is, If we sort alphabetically each list then favoriteCompanies[i] != favoriteCompanies[j].
// All strings consist of lowercase English letters only.

// https://leetcode.com/problems/people-whose-list-of-favorite-companies-is-not-a-subset-of-another-list/

// *******************************************************************************************************************
// Using includes() function from bits lib = True if every element of 2nd container lies in 1st container.
// Time complexity - N * logN + N * N  (includes has linear complexity)
// *******************************************************************************************************************
class Solution {
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
        vector<int> retVec;
        
        for(vector<string>& comp : favoriteCompanies)
            sort(comp.begin(), comp.end());
        
        for(int i=0; i < favoriteCompanies.size(); i++)
        {
            // Assume curr company is not a subset of any other company
            bool notSubset = true;
            
            // Compare with every other company lists
            for(int j=0; j < favoriteCompanies.size() && notSubset; j++)
            {
                // Skip for same company list
                if(i == j)
                    continue;
                
                // Check if curr company is subset of (included by) any other company (any other list)
                // break condition is checked in for loop
                notSubset = !includes(favoriteCompanies[j].begin(), favoriteCompanies[j].end(),
                                      favoriteCompanies[i].begin(), favoriteCompanies[i].end());
            }
            
            // Add the index to retVec if curr company was not a subset of any other company
            if(notSubset)
                retVec.push_back(i);
        }
        
        return retVec;
    }
};

// *******************************************************************************************************************
// TLE
// *******************************************************************************************************************
class Solution {    
public:
    vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {       
        vector<int> retVec;
        
        int idx = 0;
        // sort(favoriteCompanies.begin(), favoriteCompanies.end(), sizeCompare);
        
        for(vector<string>& listComp : favoriteCompanies)
        {
            int notPart = 0;
            
            // Compare with every other company lists
            for(vector<string>& listCompToCompare : favoriteCompanies)
            {
                // Skip for same company list
                if(listComp == listCompToCompare)
                    continue;
                
                if(listComp.size() > listCompToCompare.size())
                {
                    notPart++;
                    continue;
                }
                
                unordered_set<string> currCompToCompareSet (listCompToCompare.begin(), listCompToCompare.end());
                
                for(string& s : listComp)
                {
                    if(!currCompToCompareSet.count(s))
                    {
                        notPart++;
                        break;
                    }
                }
            }
            
            if(notPart == favoriteCompanies.size() - 1)
            {
                retVec.push_back(idx);
            }
            
            idx++;
        }
        
        return retVec;
    }
};