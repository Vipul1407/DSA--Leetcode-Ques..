/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //METHOD-2
    //BFS..
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(q.size())
        {
            int size= q.size();
            while(size--)
            {
                auto top= q.front();
                q.pop();
                // TreeNode* temp= top->left;
                // top->left= top->right;
                // top->right= temp;
                swap(top->left,top->right);
                if(top->left)
                {
                    q.push(top->left);
                }
                if(top->right)
                {
                    q.push(top->right);
                }
            }
        }
        return root;
    }
};
/*
    //METHOD-1
    //DFS..
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }
        TreeNode* left= invertTree(root->left);
        TreeNode* right= invertTree(root->right);
        root->left= right;
        root->right= left;
        return root;
    }
*/