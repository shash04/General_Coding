/* give a list of string, group the strings which have the same number of repeats for the same letter. for example
input: {aabb, bbaa, ac, abb, acd, bba, bab}
output: {{aabb, bbaa},  {ac}, {acd}, {abb, bba, bab}}
           
           ABB
*/
// feel free to use c++ STL
// write a function for this, and try some unit tests

#include <iostream>
#include <vector>
#include <unordered_map>
#include <bits/stdc++.h> 
using namespace std;

string getKey(const string& s)
{
  if(s.size() == 0)
    return s;
  
  string retStr;
  
  vector<int> charCnt (256, 0);
  
  for(auto& c : s)
  {
    charCnt[c]++; 
  }
  
  for(int i=0; i<256; i++)
  {
    if(charCnt[i])
      retStr += to_string(charCnt[i]) + char(i);
  }
  
  return retStr;
}

vector<vector<string>> findRepeats(const vector<string>& stringVec)
{
  unordered_map<string, vector<string>> m1;
  vector<vector<string>> retVec;
  
  for(auto& s : stringVec)
  {
    // string temp = s;
    // sort(temp.begin(), temp.end());
    
    string key = getKey(s);
    m1[key].push_back(s);
  }
  
  for(auto& entry : m1)
  {
    retVec.push_back(entry.second);
  }
  
  return retVec;
}

// "bbaabb"
/* "bbbbbbbbbbbbbbbbbbbbaaaaaaccccccccccaaaaaaaaaaaaaa"
// 8b3c4a
*/
int main()
{
  vector<string> stringVec = {"aabb", "bbaa", "ac", "abb", "acd", "bba", "bab"};
  vector<vector<string>> output = findRepeats(stringVec);
  
  for(auto v : output)
  {
    cout<<"{ ";
    for(auto entry : v)
    {
      cout<<entry<<", "; 
    }
    cout<<"}, ";  
  }
  
  return 0;
}

// aabb, bbaa, AaBb1
// "aabb" - {aabb, bbaa}
// retVec = {{AaBb1}, {aabb, bbaa}}
// traverse the map and create a final vector which is cumulation of all the vector