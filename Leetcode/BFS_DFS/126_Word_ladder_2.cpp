// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation
// sequence(s) from beginWord to endWord, such that:
// Only one letter can be changed at a time
// Each transformed word must exist in the word list. Note that beginWord is not a transformed word.

// Note:
// Return an empty list if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]

// Example 2:
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Output: []
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

// https://leetcode.com/problems/word-ladder-ii/

// Concept : Do BFS of paths instead of words
// Then the queue becomes a queue of paths

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> retVec;
        
        if(wordList.size() == 0)
            return retVec;
        
        unordered_set<string> wordSet (wordList.begin(), wordList.end());
        
        // Keep track of vsisited words in curr level. These words will never be visited again.
        unordered_set<string> visited;
        
        int level = 1;
        int minLevel = INT_MAX;
        
        queue<vector<string>> pathsQueue;
        pathsQueue.push({beginWord});
        
        while(!pathsQueue.empty())
        {
            vector<string> currPath = pathsQueue.front();
            pathsQueue.pop();
            
            if(currPath.size() > level)
            {
                // Remove all the visited words from prev level
                // Shortest path won't have repeated words across diff paths
                // for e.g if path1 = hat->hot->...->cog ; path2 = hat->hit->...hot->...->cog
                // path2 will always be longer than path1
                for(auto word: visited)
                    wordSet.erase(word);
                
                visited.clear();
                
                // If path size is greater than shortest : break
                // If not : curr level = curr path size
                if(currPath.size() > minLevel)
                    break;
                else
                    level = currPath.size();
                
            }
            
            string currWord = currPath.back();
            
            // Iterate over all possible words by changing chars of currWord
            // If present in wordSet, add it to the path
            for(int i=0; i<currWord.size(); i++)
            {
                char temp = currWord[i];
                for(char c='a'; c<='z'; c++)
                {
                    currWord[i] = c;
                    if(wordSet.find(currWord) != wordSet.end())
                    {
                        // As currPath will be reused in loop, copy it to newPath
                        vector<string> newPath = currPath;
                        newPath.push_back(currWord);
                        visited.insert(currWord);
                        
                        if(currWord == endWord)
                        {
                            retVec.push_back(newPath);
                            minLevel = level;
                        }
                        else
                            pathsQueue.push(newPath);
                    }
                    currWord[i] = temp;
                }
            }
        }
        
        return retVec;
    }
};