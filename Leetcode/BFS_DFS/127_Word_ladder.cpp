// Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:
// 1) Only one letter can be changed at a time.
// 2) Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
// Note:
// Return 0 if there is no such transformation sequence.
// All words have the same length.
// All words contain only lowercase alphabetic characters.
// You may assume no duplicates in the word list.
// You may assume beginWord and endWord are non-empty and are not the same.

// Example 1:
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
// Output: 5
// Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
// return its length 5.

// Example 2:
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
// Output: 0
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.

// https://leetcode.com/problems/word-ladder/

// Concept = Start with beginWord and visit neighbors and then their non-visited neghbors and so on (BFS) till we reach endWord.
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict (wordList.begin(), wordList.end());
        queue<string> q1;                                   // Queue to maintain neighbors for BFS
        int ladderLen = 1;                                  // Init to 1 as beginWord is counted
        q1.push(beginWord);
        while(!q1.empty())
        {
            int currNeighbors = q1.size();
            for(int i=0; i<currNeighbors; i++)              // Iterate over all current neighbors to check if endWord reached
            {
                string word = q1.front();
                q1.pop();
                
                if(word == endWord)
                    return ladderLen;
                
                dict.erase(word);                           // Current word in used. So removing from dict
                
                for(int j=0; j<word.size(); j++)            // Change every char in curr word and create all possible combinations
                {
                    char c_temp = word[j];
                    for(char c = 'a'; c <= 'z'; c++)
                    {
                        word[j] = c;
                        if(dict.find(word) != dict.end())   // If combination/neighbor is present in dict => add it to queue
                            q1.push(word);
                    }
                    word[j] = c_temp;
                }
            }
            ladderLen++;                                    // Increment ladderLen as we are past one word in dict
        }
        return 0;
    }
};
