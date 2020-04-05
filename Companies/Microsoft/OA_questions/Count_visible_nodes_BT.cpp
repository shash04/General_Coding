// In a binary tree, if in the path from root to the node A, there is no node with greater value than A’s,
// this node A is visible. We need to count the number of visible nodes in a binary tree.

// Example 1:
// Input:
//         5
//      /     \
//    3        10
//   /  \     /
// 20   21   1

// Output: 4
// Explanation: There are 4 visible nodes: 5, 20, 21, and 10.

// Example 2:
// Input:
//   -10
// 	\
// 	-15
// 	   \
// 	   -1

// Output: 2
// Explanation: Visible nodes are -10 and -1.

// https://leetcode.com/discuss/interview-question/546703/

int countVisibleNodesHelper(TreeNode* root, int max)
{
    if(root == NULL)
        return 0;
    
    int count = 0;
    if(root->val > max)
    {
        count++;
        max = root->val;
    }
    
    count += countVisibleNodesHelper(root->left, max) + countVisibleNodesHelper(root->right, max);
    return count;
}

int countVisibleNodes(TreeNode* root)
{
    return countVisibleNodesHelper(root, INT_MIN);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(10);
    root->left->left = new TreeNode(20);
    root->left->right = new TreeNode(21);
    root->right->left = new TreeNode(1);
    
    cout<<countVisibleNodes(root)<<endl;
}

// struct TreeNode{
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int val) : val(val), left(NULL), right(NULL) {}
// };