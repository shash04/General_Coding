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

// Optimized solution
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

// My original solution
// vector dist holds all distances. distMap holds vector of points for each distance
// sort dist vector and get first k points from map
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<double> dist;
        unordered_map<double, vector<vector<int>>> distMap;
        vector<vector<int>> ret;
        for(int i=0; i<points.size(); i++)
        {
            int x = points[i][0];
            int y = points[i][1];
            double curr_dist = sqrt(x*x + y*y);
            dist.push_back(curr_dist);
            distMap[curr_dist].push_back(points[i]);
        }
        
        sort(dist.begin(), dist.end());
        int n = dist.size();
        
        int kIter = 0;
        while(kIter != K)
        {
            vector<vector<int>> curr_dist_vec = distMap[dist[kIter]];
            for(int i=0; i<curr_dist_vec.size() && kIter != K; i++)
            {
                vector<int> currPoint = curr_dist_vec[i];
                ret.push_back(currPoint);
                kIter++;
            }            
        }
        
        return ret;
    }
};