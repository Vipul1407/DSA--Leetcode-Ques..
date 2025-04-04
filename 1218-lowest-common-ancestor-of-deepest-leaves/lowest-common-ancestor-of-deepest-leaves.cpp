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
    //2 PASS storing height in mp and using maxdepth
    
    int maxdepth=0;
    void calculate_height(TreeNode* root, int d, unordered_map<int,int>&mp)
    {
        if(!root)
        {
            return;
        }
        mp[root->val]=d;
        maxdepth= max(maxdepth,d);
        maxdepth= max(maxdepth,d);
        calculate_height(root->left,d+1,mp);
        calculate_height(root->right,d+1,mp);
    }
    TreeNode* LCA(TreeNode* root, unordered_map<int,int>&mp)
    {
        if(!root)
        {
            return NULL;
        }
        if(mp[root->val]==maxdepth)
        {
            return root;
        }
        TreeNode* left= LCA(root->left,mp);
        TreeNode* right= LCA(root->right,mp);
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
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        unordered_map<int,int>mp;
        calculate_height(root,0,mp);
        return LCA(root,mp);
    }
};
/*
    //METHOD-2
    //1 PASS not storing height in mp and not using maxdepth

    pair<int,TreeNode*> LCA(TreeNode* root)
    {
        if(!root)
        {
            return {0,NULL};
        }
        auto left= LCA(root->left);
        auto right= LCA(root->right);
        if(left.first>right.first)
        {
            return {left.first+1,left.second};
        }
        else if(right.first>left.first)
        {
            return {right.first+1,right.second};
        }
        else
        {
            return {left.first+1,root};
        }
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) 
    {
        return LCA(root).second;
    }
*/