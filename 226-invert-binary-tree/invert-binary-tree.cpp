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
    //METHOD-3
    //BFS..
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            auto top= q.front();
            q.pop();
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
        TreeNode* temp= root->left;
        root->left= root->right;
        root->right= temp;
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
    //METHOD-2
    //DFS..
    TreeNode* invertTree(TreeNode* root) 
    {
        if(!root)
        {
            return root;
        }
        swap(root->left,root->right);
        invertTree(root->left);
        invertTree(root->right);
        return root;
    }
*/