// You are given a string S consisting of N letters 'a' and/or 'b'.
// In one move, you can swap one letter for the other ('a' for 'b' or 'b' for 'a').

// Write a function solution that, given such a string S, returns the minimum number of moves required to obtain a string
// containing no instances of three identical consecutive letters.

// Examples: 1. Given S = "baaaaa", the function should return 1.
// The string without three identical consecutive letters which can be obtained in one move is "baabaa".

// 2. Given S = "baaabbaabbba", the function should return 2.
// There are four valid strings obtainable in two moves: for example, "bbaabbaabbaa".

// 3. Given S = "baabab", the function should return 0.

// Write an efficient algorithm for the following assumptions:
// • N is an integer within the range [0..200,000);
// • string S consists only of the characters "a" and/or "b".

// https://leetcode.com/discuss/interview-question/398026/

/* Concept :
There are fixed pattern we need to consider:
3 consecutive : baaab , replace the middle a
4 consecutive : baaaab, replace the third a
5 consecutive : baaaaab, replace the third a

for more than 5, replace the third char and it can be reduced as the above three conditions
6 consecutive : baaaaaab --> baabaaab ->trans to baaab with 1 replacement -> trans to bb with 2 replancement
10 consecutive : baaaaaaaaaab --> baabaaaaaaab ->trans to baaaaaaab with 1 replacement -> trans to baaaab with 2 replacement -> trans to baab with 3 replacement, done.

therefore, we can see the rule, counter += (consecutive char number)/3
*/

int minMovesToGetStr(string& s)
{
    int retVal = 0;

    for(int i=0; i < s.size(); )
    {
        int next = i + 1;

        // move the next pointer till different consecutive chars
        while(next < s.size() && s[i] == s[next])
            next++;

        int diff = next - i;

        if(diff >= 3)
        {
            while(diff > 5)
            {
                retVal++;
                diff -= 3;
            }
            if(diff <= 5)
            {
                retVal++;
            }
        }
        // Move i to next pointer
        i = next;
    }

    return retVal;
}

int main()
{
    string s = "baaabbaabbba";
    cout<<"Min moves to get string without 3 identical chars : " << s << "\t" << minMovesToGetStr(s) <<endl;
}