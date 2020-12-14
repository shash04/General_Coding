// We have a list of points on the plane.  Find the K closest points to the origin (0, 0).
// (Here, the distance between two points on a plane is the Euclidean distance.)
// You may return the answer in any order.  The answer is guaranteed to be unique (except for the order that it is in.)

// Example 1:
// Input: points = [[1,3],[-2,2]], K = 1
// Output: [[-2,2]]
// Explanation: 
// The distance between (1, 3) and the origin is sqrt(10).
// The distance between (-2, 2) and the origin is sqrt(8).
// Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
// We only want the closest K = 1 points from the origin, so the answer is just [[-2,2]].

// Example 2:
// Input: points = [[3,3],[5,-1],[-2,4]], K = 2
// Output: [[3,3],[-2,4]]
// (The answer [[-2,4],[3,3]] would also be accepted.)

// https://leetcode.com/problems/k-closest-points-to-origin/

// ****************************************************************************
// Quickselect implementation
// ****************************************************************************
class Solution {
    bool farther(vector<int>& p, vector<int>& q)
    {
        return (p[0] * p[0] + p[1] * p[1]) > (q[0] * q[0] + q[1] * q[1]);
    }
    
    bool closer(vector<int>& p, vector<int>& q)
    {
        return (p[0] * p[0] + p[1] * p[1]) < (q[0] * q[0] + q[1] * q[1]);
    }
    
    int partition(vector<vector<int>>& points, int left, int right)
    {
        // Decide left point as pivot
        // At the end of this function point at pivot will be properly placed in the array and
        // all points before pivot will be closer to origin
        int pivot = left;
        int l = left + 1, r = right;
        
        while (l <= r)
        {
            // If left point is farther and right point is closer than pivot - swap left and right
            if (farther(points[l], points[pivot]) && closer(points[r], points[pivot]))
            {
                swap(points[l++], points[r--]);
            }
            // Else if left point is closer than pivot - increment left ptr
            if (!farther(points[l], points[pivot]))
            {
                l++;
            }
            // Else if right pointer is farther than pivot - decrement right ptr
            if (!closer(points[r], points[pivot]))
            {
                r--;
            }
        }
        
        swap(points[pivot], points[r]);
        return r;
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int left = 0;
        int right = points.size() - 1;
        
        while(true)
        {
            int p = partition(points, left, right);
            
            if(p == K - 1)
                break;
            else if(p < K - 1)
                left = p + 1;
            else
                right = p - 1;
        }
        
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

// ****************************************************************************
// Optimized solution - using nth_element function
// ****************************************************************************
class Solution {
public:
  static bool isLhsSmaller(const vector<int>& lhs, const vector<int> &rhs) {
    return lhs[0]*lhs[0] + lhs[1]*lhs[1] < rhs[0]*rhs[0] + rhs[1]*rhs[1];
  }

  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    nth_element(points.begin(), points.begin() + K, points.end(), isLhsSmaller);
    points.resize(K);
    return points;
  }
};

// ****************************************************************************
// Ordered Map with key - distance and val - vector of points with that dist
// ****************************************************************************
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        map<double, vector<vector<int>>> distMap;
        vector<vector<int>> result;

        // Populate distMap. As it is ordered map, entries will be sorted according to dist
        for(int i = 0; i < points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];

            double curr_dist = sqrt(x*x + y*y);

            distMap[curr_dist].push_back(points[i]);
        }
        
        // Iterate over map and add first K points to result
        for(auto& entry : distMap)
        {
            vector<vector<int>> curPoints = entry.second;
            
            for(int i = 0; i < curPoints.size() && K; i++)
            {
                result.push_back(curPoints[i]);
                K--;
            }
        }
        
        return result;
    }
};

// ****************************************************************************
// Using priority Queue
// ****************************************************************************
class Solution {
    double getDistFromOrigin(const vector<int>& a)
    {
        int x = a[0];
        int y = a[1];
        
        return sqrt(x*x + y*y);
    }
    
    struct mySort
    {
        bool operator()(const pair<double, vector<int>>& a, const pair<double, vector<int>>& b)
        {
            return a.first <= b.first;
        }
    };
    
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> result;
        
        if(points.size() < K)
            return result;
        
        priority_queue<pair<double, vector<int>>, vector<pair<double, vector<int>>>, mySort> pq;
        
        for(vector<int>& point : points)
        {
            double curDist = getDistFromOrigin(point);
            
            pq.push(make_pair(curDist, point));
            
            if(pq.size() > K)
                pq.pop();
        }
        
        while(!pq.empty())
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};