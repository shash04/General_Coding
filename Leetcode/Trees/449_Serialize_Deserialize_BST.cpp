// Serialization is the process of converting a data structure or object into a sequence of bits so that it can be
// stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed
// later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your
// serialization/deserialization algorithm should work. You just need to ensure that a binary search tree can be
// serialized to a string and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

// Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.

// https://leetcode.com/problems/serialize-and-deserialize-bst/

// ******************************************************************************************************************
// Using BFS approach
// ******************************************************************************************************************
class Codec {
private:
    void helperSerialize(TreeNode* root, string& serializedStr)
    {
        queue<TreeNode*> q1;
        q1.push(root);
        
        while(!q1.empty())
        {
            int qSize = q1.size();
            while(qSize--)
            {
                TreeNode* currNode = q1.front();
                q1.pop();
                if(currNode == NULL)
                    serializedStr += "N ";
                else
                {
                    serializedStr += to_string(currNode->val) + " ";
                    q1.push(currNode->left);
                    q1.push(currNode->right);
                }
            }
        }
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string serializedStr;
        helperSerialize(root, serializedStr);
        return serializedStr;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream ss(data);
        queue<TreeNode*> q1;
        string rootVal, leftVal, rightVal;

        ss >> rootVal;
        if(rootVal == "N")
            return NULL;
        
        TreeNode* root = new TreeNode(stoi(rootVal));
        q1.push(root);
        
        while(!q1.empty())
        {
            int qSize = q1.size();
            while(qSize-- && ss)
            {
                TreeNode* currNode = q1.front();
                q1.pop();

                if(!(ss >> leftVal))
                    break;

                if(leftVal == "N")
                {
                    currNode->left = NULL;
                }
                else
                {
                    currNode->left = new TreeNode(stoi(leftVal));
                    q1.push(currNode->left);
                }

                if(!(ss >> rightVal))
                    break;               
                
                if(rightVal == "N")
                {
                    currNode->right =  NULL;
                }
                else
                {
                    currNode->right = new TreeNode(stoi(rightVal));
                    q1.push(currNode->right);
                } 
                
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// ******************************************************************************************************************
// Using DFS approach
// ******************************************************************************************************************
class Codec {
private:
    void serializeHelper(TreeNode* root, ostringstream& oss)
    {
        if(root == NULL)
        {
            oss << "N ";
            return;
        }
        oss << root->val << " ";
        serializeHelper(root->left, oss);
        serializeHelper(root->right, oss);
    }
    
    TreeNode* deserializeHelper(istringstream& iss)
    {
        string currVal;
        iss >> currVal;
        if(currVal == "N")
            return NULL;
        TreeNode* currNode = new TreeNode(stoi(currVal));
        currNode->left = deserializeHelper(iss);
        currNode->right = deserializeHelper(iss);
        return currNode;
    }
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream oss;
        serializeHelper(root, oss);
        return oss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream iss(data);
        return deserializeHelper(iss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));