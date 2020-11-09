// Given a string and a set of delimiters, reverse the words in the string while maintaining the relative order of the delimiters.
// For example, given "hello/world:here", return "here/world:hello"

// Follow-up: Does your solution work for the following cases: "hello/world:here/", "hello//world:here"

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

string reverseStr(const string& s)
{
  if(s.size() == 0)
    return s;

  string retStr;

  int n = s.size();

  vector<string> revVec;
  vector<string> delimiterVec;

  bool isFirstD = false;

  if(!isalpha(s[0]))
    isFirstD = true;

  string word;

  int i = 0;
  while(i < n)
  {
    if(isalpha(s[i]))
    {
      word += s[i++];
    }
    else
    {
      revVec.push_back(word);
      word.clear();

      string currDStr;

      while(i < n && !isalpha(s[i]))
        currDStr += s[i++];

      delimiterVec.push_back(currDStr);
    }
  }

  if(word.size())
      revVec.push_back(word);

  reverse(revVec.begin(), revVec.end());

  int k = 0;
  for(string& currStr : revVec)
  {
    string d = (k < delimiterVec.size()) ? delimiterVec[k++] : "";

    if(isFirstD)
    {
      retStr += d + currStr;
    }
    else
    {
      retStr += currStr + d;
    }
  }

  return retStr;
}

int main() {
  string s1 = "@hello//world: amazing##here@";
  cout<<reverseStr(s1)<<endl;
}