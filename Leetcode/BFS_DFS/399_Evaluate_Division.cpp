// Equations are given in the format A / B = k, where A and B are variables represented as strings, and k is a real number (floating point number).
// Given some queries, return the answers. If the answer does not exist, return -1.0.

// Example:
// Given a / b = 2.0, b / c = 3.0.
// queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
// return [6.0, 0.5, -1.0, 1.0, -1.0 ].

// The input is: vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries ,
// where equations.size() == values.size(), and the values are positive. This represents the equations. Return vector<double>.

// According to the example above:
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 

// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.

// https://leetcode.com/problems/evaluate-division/

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string, unordered_map<string, double>> m1;
        vector<double> result;
        int n = values.size();
        
        fillMap(m1, equations, values);
        
        for(int i=0; i<queries.size(); i++)
        {
            unordered_set<string> s;
            double res = getResult(queries[i][0], queries[i][1], m1, s);
            if(res != 0)
                result.push_back(res);
            else
                result.push_back(-1);
        }
        return result;
    }
    
    void fillMap(unordered_map<string, unordered_map<string, double>> &m1,
                vector<vector<string>>& equations,
                vector<double>& values)
    {
        int n = values.size();
        for(int i=0; i<n; i++)
        {
            m1[equations[i][0]].insert(make_pair(equations[i][1], values[i]));
            m1[equations[i][1]].insert(make_pair(equations[i][0], 1 / values[i]));
        }
    }
    
    double getResult( string num, string den,
                unordered_map<string, unordered_map<string, double>> &m1,
                unordered_set<string> &s)
    {
        if(m1[num].find(den) != m1[num].end())
            return m1[num][den];
        
        for(auto iter=m1[num].begin(); iter!=m1[num].end(); iter++)
        {
            if(s.find(iter->first) == s.end())
            {
                s.insert(iter->first);
                double tmp = getResult(iter->first, den, m1, s);
                if(tmp)
                    return tmp*iter->second; 
            }
        }
        return 0;
    }
};