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
    //METHOD-1
    //2PASS + maxdepth variable
    void calculate_height(TreeNode* root, unordered_map<int,int>&mp, int d, int &maxdepth)
    {
        if(!root)
        {
            return;
        }
        mp[root->val]=d;
        maxdepth= max(maxdepth,d);
        calculate_height(root->left,mp,d+1,maxdepth);
        calculate_height(root->right,mp,d+1,maxdepth);
    }
    TreeNode* LCA(TreeNode* root, unordered_map<int,int>&mp, int &maxdepth)
    {
        if(!root)
        {
            return NULL;
        }
        if(mp[root->val]==maxdepth)
        {
            return root;
        }
        TreeNode*left= LCA(root->left,mp,maxdepth);
        TreeNode*right= LCA(root->right,mp,maxdepth);
        if(!left)
        {
            return right;
        }
        else if(!right)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        int maxdepth=0;
        unordered_map<int,int>mp;
        calculate_height(root,mp,0,maxdepth);
        return LCA(root,mp,maxdepth);
    }
};