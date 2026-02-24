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
    //int return type..
    int rec(int curr,TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        curr= (curr<<1) |root->val;
        if(!root->left && !root->right)
        {
            return curr;
        }
        int left= rec(curr,root->left);
        int right= rec(curr,root->right);
        return left+right;
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        return rec(0,root);
    }
};
/*
    //METHOD-1
    //void return type..
    void rec(int curr,TreeNode* root,int &ans)
    {
        if(!root)
        {
            return;
        }
        curr= (curr<<1) |root->val;
        if(!root->left && !root->right)
        {
            ans+= curr;
            return;
        }
        rec(curr,root->left,ans);
        rec(curr,root->right,ans);
    }
    int sumRootToLeaf(TreeNode* root) 
    {
        int ans=0;
        rec(0,root,ans);
        return ans;
    }
*/