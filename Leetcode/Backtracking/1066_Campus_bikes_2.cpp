

class Solution {
public:
    int assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        int minSum = INT_MAX;
        vector<bool> visited (bikes.size(), false);
        DFS(workers, bikes, 0, visited, 0, minSum);
        return minSum;
    }
    
    void DFS(vector<vector<int>>&workers, vector<vector<int>>& bikes, int i, vector<bool>& visited, int curr_sum, int& minSum)
    {
        if(i == workers.size())
        {
            minSum = min(minSum, curr_sum);
            return;
        }
        
        if(curr_sum > minSum)
            return;
        
        for(int j=0; j<bikes.size(); j++)
        {
            if(!visited[j])
            {
                visited[j] = true;
                curr_sum += calculateMD(workers[i], bikes[j]);
                DFS(workers, bikes, i+1, visited, curr_sum, minSum);
                visited[j] = false;
            }
        }
    }
    
    int calculateMD(vector<int>& worker, vector<int>& bike)
    {
        return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
    }
};
