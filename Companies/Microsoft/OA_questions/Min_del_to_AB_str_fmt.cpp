// We are given a string S of length N consisting only of letters 'A' and/or 'B'.
// Our goal is to obtain a string in the format "A...AB...B" (all letters 'A' occur before all letters 'B') by deleting some letters from S.
// In particular, strings consisting only of letters 'A' or only of letters 'B' fit this format.

// Write a function:
// class Solution { public int solution(String s); }
// that, given a string S, returns the minimum number of letters that need to be deleted from S in order to obtain a string in the above format.

// Examples:
// 1. Given S="BAAABAB", the function should return 2. We can obtain "AAABB' by deleting the first occurrence of 'B' and the last occurrence of 'A'.

// 2. Given S="BBABAA", the function should return 3. We can delete all occurrences of 'A' or all occurrences of 'B'.

// 3. Given S = "AABBBB", the function should return O. We do not have to delete any letters, because the given string is already in the expected format.

// Write an efficient algorithm for the following assumptions:
// N is an integer within the range (1..100,000); • string S consists only of the characters 'A' and/or 'B'.

// https://leetcode.com/discuss/interview-question/421975/

/*
Approach = del all B before partition and all A after partition
For example take the string BAABAB, the partitions are as follows:
init    | BAABAB -> BBB         3A      = 3
0       B | AABAB -> BB         1B + 3A = 4
1       BA | ABAB -> ABB        1B + 2A = 3
2       BAA | BAB -> AABB       1B + 1A = 2
3       BAAB | AB -> AAB        2B + 1A = 3
4       BAABA | B -> AAAB       2B + 0A = 2
5       BAABAB | -> AAA         3B      = 3
                                min = 2
*/

int minDelForPattern(string s)
{
    int minDel = 0;
    int rA = 0;
    int lB = 0;
    
    // Get total number of A
    for(char& c : s)
    {
        if(c == 'A')
            rA++;
    }
    
    // First case - delete all A
    minDel = rA;
    
    // iterate over all idx to get required fmt by
    // del all B before idx and all A after idx
    for(int i=0; i < s.size(); i++)
    {
        if(s[i] == 'A')
            rA--;
        else
            lB++;
        
        // find min of curr min and del required for curr idx
        minDel = min(minDel, lB + rA);
    }
    
    return minDel;    
}

int main() {
    string s1 = "BAABAB";
    string s2 = "BBABAA";
    string s3 = "AABBBB";
    cout<<minDelForPattern(s1)<<endl;
    cout<<minDelForPattern(s2)<<endl;
    cout<<minDelForPattern(s3)<<endl;
}