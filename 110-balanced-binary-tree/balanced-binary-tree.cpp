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
    //TC= O(N)
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int left= dfs(root->left);
        if(left==-1)
        {
            return -1;
        }
        int right= dfs(root->right);
        if(right==-1)
        {
            return -1;
        }
        if(abs(left-right)>1)
        {
            return -1;
        }
        return 1+max(left,right);
    }
    bool isBalanced(TreeNode* root) 
    {
        return dfs(root)!=-1;
    }
};
/*
    //METHOD-1
    //TC= O(N^2)
    int height(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int lht= height(root->left);
        int rht= height(root->right);
        return 1+max(lht,rht);
    }
    bool isBalanced(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }
        int lefth= height(root->left);
        int righth= height(root->right);
        if(abs(lefth-righth)>1)
        {
            return false;
        }
        return isBalanced(root->left) && isBalanced(root->right);
    }
*/