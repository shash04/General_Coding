// Given a binary tree, return all paths from the root to leaves.

// For example, given the tree:

//    1
//   / \
//  2   3
//     / \
//    4   5
// Return [[1, 2], [1, 3, 4], [1, 3, 5]].

#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
  int val;
  TreeNode* left;
  TreeNode* right;
  
  TreeNode(int v) : val(v), left(NULL), right(NULL) {} 
};

class Solution{
  void helper(TreeNode* root, vector<vector<int>>& retVec, vector<int>& currVec)
  {
    currVec.push_back(root->val);
    
    if(root->left == NULL && root->right == NULL)
    {
      retVec.push_back(currVec);
      currVec.pop_back();
      return;
    }
    
    if(root->left)
      helper(root->left, retVec, currVec);
    
    if(root->right)
      helper(root->right, retVec, currVec);
    
    currVec.pop_back();
  }
public:
  vector<vector<int>> allPaths(TreeNode* root)
  {
    vector<vector<int>> retVec;
    
    if(root == NULL)
      return retVec;
    
    vector<int> currVec;
    
    helper(root, retVec, currVec);
    
    return retVec;
  }
};

// To execute C++, please define "int main()"
int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);
  
  Solution s1;
  vector<vector<int>> ans = s1.allPaths(root);
  
  for(auto& v : ans)
  {
    cout<<"[";
    for(int& n : v)
    {
      cout<<n<<",";
    }
    cout<<"]"<<endl;
  }
  
  return 0;
}
