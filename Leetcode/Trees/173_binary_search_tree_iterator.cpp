// Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
// Calling next() will return the next smallest number in the BST.

// https://leetcode.com/problems/binary-search-tree-iterator/

// Solution 1: Optimal memory usage
// Only keep left nodes of tree in Stack.
class BSTIterator {
public:
    stack<TreeNode*> sNodes;
    
    BSTIterator(TreeNode* root) {       
        fillStack(sNodes, root);
    }
    
    /** @return the next smallest number */
    int next() {
        if(sNodes.empty())
            return -1;
        TreeNode* temp_node = sNodes.top();
        sNodes.pop();
        fillStack(sNodes, temp_node->right);
        return temp_node->val;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(sNodes.empty())
            return false;
        else
            return true;
    }
    
    void fillStack(stack<TreeNode*> &sNodes, TreeNode* root)
    {
        if(root == NULL)
            return;      
        sNodes.push(root);
        fillStack(sNodes, root->left);
    }
};

// Solution 2: Works but takes more memory.
class BSTIterator {
public:
    stack<TreeNode*> sNodes;
    
    BSTIterator(TreeNode* root) {       
        fillStack(sNodes, root);
    }
    
    /** @return the next smallest number */
    int next() {
        if(sNodes.empty())
            return -1;
        int ret = sNodes.top()->val;
        sNodes.pop();
        return ret;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(sNodes.empty())
            return false;
        else
            return true;
    }
    
    void fillStack(stack<TreeNode*> &sNodes, TreeNode* root)
    {
        if(root == NULL)
            return;
        fillStack(sNodes, root->right);        
        sNodes.push(root);
        fillStack(sNodes, root->left);
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */