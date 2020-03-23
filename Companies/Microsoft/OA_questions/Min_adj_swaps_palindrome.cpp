// Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome.
// If not possible, return -1.

// Example 1:
// Input: "mamad"
// Output: 3

// Example 2:
// Input: "asflkj"
// Output: -1

// Example 3:
// Input: "aabb"
// Output: 2

// Example 4:
// Input: "ntiin"
// Output: 1
// Explanation: swap 't' with 'i' => "nitin"

// https://leetcode.com/discuss/interview-question/351783/

int minSwapsToPalindrome(string& s)
{
    if(s.size() == 0)
        return -1;
    
    int numSwaps = 0;
    
    if(!isPalindromePossible(s))
        return -1;
    
    int lPtr = 0, rPtr = s.size() - 1;
    
    while(lPtr < rPtr)
    {
        if(s[lPtr] == s[rPtr])
        {
            lPtr++; rPtr--;
            continue;
        }
        
        int k = rPtr;
        
        // Move k till char mismatch found
        while(k > lPtr && s[lPtr] != s[k])
            k--;
        
        // If no matching character found
        if(k == lPtr)
        {
            swap(s, lPtr, lPtr + 1);
            numSwaps++;
        }
        else
        {
            // swap until rPtr char is same as lPtr
            while(k < rPtr)
            {
                swap(s, k, k + 1);
                numSwaps++;
                k++;
            }
            lPtr++; rPtr--;
        }
    }
    
    return numSwaps;
}

void swap(string& s, int p1, int p2)
{
    int temp = s[p1];
    s[p1] = s[p2];
    s[p2] = temp;
}

bool isPalindromePossible(string& s)
{
    vector<int> count (128, 0);
        
    for(int i=0; i < s.size(); i++)
    {
        if(count[s[i]] == 1)
            count[s[i]]--;
        else
            count[s[i]]++;
    }

    int flag = 0;
    for(int i=0; i < 128; i++)
    {
        if(count[i] > 0)
            flag++;
        if(flag > 1)
            return false;
    }
    return true;
}

int main() {
    string s = "asflkj";
    cout<<minSwapsToPalindrome(s)<<endl;
}