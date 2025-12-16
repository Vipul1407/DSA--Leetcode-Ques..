/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(!root || root==p || root==q)
        {
            return root;
        }
        TreeNode* left= lowestCommonAncestor(root->left,p,q);
        TreeNode* right= lowestCommonAncestor(root->right,p,q);
        if(left==NULL)
        {
            return right;
        }
        else if(right==NULL)
        {
            return left;
        }
        else
        {
            return root;
        }
    }
};
/*
    //METHOD-2
    //STRING IN VECTORS..
    bool store(TreeNode* root, TreeNode* p, vector<int>&v)
    {
        if(!root)
        {
            return false;
        }
        v.push_back(root->val);
        if(root==p)
        {
            return true;
        }
        if(store(root->left,p,v) || store(root->right,p,v))
        {
            return true;
        }
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        vector<int>v1;
        vector<int>v2;
        store(root,p,v1);
        store(root,q,v2);
        int i=0;
        while(i<v1.size() && i<v2.size() && v1[i]==v2[i])
        {
            i++;
        }
        return new TreeNode(v1[i-1]);
    }
*/