// University has exactly one turnstile. It can be used as exit or entrance. ith person comest to turnstile at time[i] and
// wants to either exit if direction[i] = 1 or enter if direction[i] = 0. People form two queues - one to exit and one to enter
// They are ordered by the time when they came to the turnstile and if times are equal, by their indices.size_t
// If some person wants to enter and other person wants to exit at same moment, there are 3 cases:
// * If in the previous second, the turnstile was not used (maybe used before but not the prev second), then the person
//   who wants to exit gets priority
// * If in the previous second, the turnstile was used as an exit, then person who wants to exit gets priority
// * If in the previous second, the turnstile was used as an entrance, then person who wants to enter gets priority

// Passing through the turnstile takes one second.
// For each person, find the time when they will pass through the turnstile

// Example 1:
// Input
// Arrival times = {0, 0, 1, 5}
// Direction = {0, 1, 1, 0}

// Output = {2, 0, 1, 5}

// https://leetcode.com/discuss/interview-question/699973/

vector<int> getTurnstileTimes(vector<int>& arrival, vector<int>& direction)
{
    int n = arrival.size();
    vector<int> result (n, 0);
    
    if(n == 0)
        return result;
    
    queue<pair<int, int>> entryQ, exitQ;
    
    // Populate entry and exit queues
    for(int i = 0; i < n; i++)
    {
        if(direction[i] == 1)
            exitQ.push(make_pair(arrival[i], i));
        else
            entryQ.push(make_pair(arrival[i], i));
    }
    
    int time = 0, dir = -1;
    
    while(!entryQ.empty() || !exitQ.empty())
    {
        if(!exitQ.empty() && exitQ.front().first <= time && (dir == 1 || dir == -1 || entryQ.empty() || entryQ.front().first > time))
        {
            auto cur = exitQ.front();
            exitQ.pop();
            result[cur.second] = time;
            dir = 1;
        }
        else if(!entryQ.empty() && entryQ.front().first <= time)
        {
            auto cur = entryQ.front();
            entryQ.pop();
            result[cur.second] = time;
            dir = 0;
        }
        else
        {
            dir = -1;
        }
        
        time++;
    }
    
    return result;
}

void printArr(vector<int>& arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    vector<int> arr1 = {0, 0, 1, 5};
    vector<int> dir1 = {0, 1, 1, 0};
    
    vector<int> arr2 = {1, 1, 3, 3, 4, 5, 6, 7, 7};
    vector<int> dir2 = {1, 1, 0, 0, 0, 1, 1, 1, 1};
    
    vector<int> result = getTurnstileTimes(arr2, dir2);
    
    printArr(result);
}