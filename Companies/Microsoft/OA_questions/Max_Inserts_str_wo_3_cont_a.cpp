// Write a function solution that, given a string S consisting of N characters, retums the maximum number of letters 'a'
// that can be inserted into S (including at the front and end of S) so that the resulting string doesn't contain three
// consecutive letters 'a'. If string S already contains the substring 'aaa', then your function should return -1.

// Examples:
// 1. Given S = "aabab", the function should return 3, because a string "aabaabaa' can be made.

// 2. Given S="dog", the function should return 8, because a string "aadaaoaagaa' can be made.

// 3. Given S = "aa", the function should return 0, because no longer string can be made.

// 4. Given S = "baaaa", the function should return -1, because there is a substring 'aaa'.

// Write an efficient algorithm for the following assumptions:
// • N is an integer within the range (1..200,000); • string S consists only of lowercase letters a-z).

// https://leetcode.com/discuss/interview-question/398056/

int maxNumAInserted(string s)
{
    int retVal = 0;
    int count = 0;
    int idx = 0;
    
    while(idx < s.size())
    {
        if(s[idx] == 'a')
        {
            if(count >= 3)
                return -1;
            count++;
        }
        else
        {
            retVal += 2 - count;
            count = 0;
        }
        idx++;
    }
    
    if(count >= 3)
        return -1;
    
    retVal += 2 - count;
    
    return retVal;
}

int main() {
    string s = "aaba";
    cout<<maxNumAInserted(s);
}