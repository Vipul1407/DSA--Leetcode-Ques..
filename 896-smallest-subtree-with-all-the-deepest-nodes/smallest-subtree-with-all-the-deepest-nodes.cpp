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
    pair<int,TreeNode*> solve(TreeNode* root)
    {
        if(!root)
        {
            return {0,NULL};
        }
        auto left= solve(root->left);
        auto right= solve(root->right);
        if(left.first > right.first)
        {
            return {left.first+1,left.second};
        }
        else if(right.first > left.first)
        {
            return {right.first+1,right.second};
        }
        //both are same..
        else
        {
            return {left.first+1, root};
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        unordered_map<int,int>mp;
        int maxdepth=0;
        return solve(root).second;
    }  
};
/*
    //METHOD-1
    void storedepth(TreeNode* root, int depth, int &maxdepth, unordered_map<int,int>&mp)
    {
        if(!root)
        {
            return;
        }
        mp[root->val]= depth;
        maxdepth= max(maxdepth, depth);
        storedepth(root->left,depth+1,maxdepth,mp);
        storedepth(root->right,depth+1,maxdepth,mp);
    }
    TreeNode* solve(TreeNode* root, unordered_map<int,int>&mp, int &maxdepth)
    {
        if(!root)
        {
            return NULL;
        }
        if(mp[root->val]==maxdepth)
        {
            return root;
        }
        TreeNode* left= solve(root->left,mp,maxdepth);
        TreeNode* right= solve(root->right,mp,maxdepth);
        if(left!=NULL && right!=NULL)
        {
            return root;
        }
        else if(left!=NULL)
        {
            return left;
        }
        else
        {
            return right;
        }
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) 
    {
        unordered_map<int,int>mp;
        int maxdepth=0;
        storedepth(root,0,maxdepth,mp);
        return solve(root,mp,maxdepth);
    }
*/