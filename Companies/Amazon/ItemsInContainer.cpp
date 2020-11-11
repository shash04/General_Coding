// Amazon would like to know how much inventory exists in their closed inventory compartments. Given a string s
// consisting of items as "*" and closed compartments as an open and close "|", an array of starting indices
// startIndices, and an array of ending indices endIndices, determine the number of items in closed compartments
// within the substring between the two indices, inclusive.

// An item is represented as an asterisk ('*' = ascii decimal 42)
// A compartment is represented as a pair of pipes that may or may not have items between them ('|' = ascii decimal 124).

// Example

// s = '|**|*|*'

// startIndices = [1, 1]

// endIndices = [5, 6]

// The string has a total of 2 closed compartments, one with 2 items and one with 1 item. For the first pair of
// indices, (1, 5), the substring is '|**|*'. There are 2 items in a compartment.

// For the second pair of indices, (1, 6), the substring is '|**|*|' and there are 2 + 1 = 3 items in compartments.

// Both of the answers are returned in an array, [2, 3].

// Function Description .

// Complete the numberOfItems function in the editor below. The function must return an integer array that contains
// the results for each of the startIndices[i] and endIndices[i] pairs.

// numberOfItems has three parameters:

// s: A string to evaluate

// startIndices: An integer array, the starting indices.

// endIndices: An integer array, the ending indices.

// Constraints

// 1 ≤ m, n ≤ 105
// 1 ≤ startIndices[i] ≤ endIndices[i] ≤ n
// Each character of s is either '*' or '|'

// Input Format For Custom Testing

// The first line contains a string, S.
// The next line contains an integer, n, the number of elements in startIndices.
// Each line i of the n subsequent lines (where 1 ≤ i ≤ n) contains an integer, startIndices[i].
// The next line repeats the integer, n, the number of elements in endIndices.
// Each line i of the n subsequent lines (where 1 ≤ i ≤ n) contains an integer, endIndices[i].

// Sample Case 0
// Sample Input For Custom Testing

// STDIN Function

// *|*| -> s = "*|*|"

// 1 -> startIndices[] size n = 1
// 1 -> startIndices = 1
// 1 -> endIndices[] size n = 1
// 3 -> endIndices = 3

// ** Sample Output**
// 0

// Explanation
// s = *|*|

// n = 1
// startIndices = [1]
// n = 1
// startIndices = [3]

// The substring from index = 1 to index = 3 is '|'. There is no compartments in this string.

vector<int> getItemsInContainer(const string& s, const vector<int>& startIndices, const vector<int>& endIndices)
{
    int n = startIndices.size(), sLen = s.size();
    vector<int> result (n, 0);
    vector<int> left (sLen, -1), right (sLen, -1), stars (sLen, 0);
    
    int leftIdx = 0, rightIdx = 0, starCount = 0;
    // Populate left vector and stars vector
    for(int i = 0; i < sLen; i++)
    {
        if(s[i] == '|')
            leftIdx = i;
        else if(s[i] == '*')
            starCount++;
        
        left[i] = leftIdx;
        stars[i] = starCount;
    }
    
    // Populate right vector
    for(int i = sLen - 1; i >= 0; i--)
    {
        if(s[i] == '|')
            rightIdx = i;
        right[i] = rightIdx;
    }
    
    // Fill result vector
    for(int i = 0; i < n; i++)
    {
        int leftWall = right[startIndices[i] - 1];
        int rightWall = left[endIndices[i] - 1];
        
        if(leftWall >= rightWall)
            result[i] = 0;
        else
            result[i] = stars[rightWall] - stars[leftWall];
    }
    
    return result;
}

int main() {
    vector<string> s = {"|**|*|*", "*|*|", "*|*|*|", "|**|***|*|****|", "|**|*|***", "***|**|*" };
    vector<vector<int>> startIndices = {{1, 1}, {1}, {1},{9, 5}, {1,1}, {1} };
    vector<vector<int>> endIndices = {{5, 6}, {3}, {6}, {15, 14}, {7,8}, {3}};    
    
    for(int k = 0; k < s.size(); k++)
    {
        vector<int> result = getItemsInContainer(s[k], startIndices[k], endIndices[k]);
        for(int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }
}