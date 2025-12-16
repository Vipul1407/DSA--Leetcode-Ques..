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

    //SC= O(N) INORDER IS ALWAYS SORTED..
    void inorder(TreeNode*root, vector<int>&ans)
    {
        if(!root)
        {
            return;
        }
        inorder(root->left,ans);
        ans.push_back(root->val);
        inorder(root->right,ans);
    }
    bool isValidBST(TreeNode* root) 
    {
        vector<int>ans;
        inorder(root,ans);
        int n=ans.size();
        for(int i=0;i<n-1;i++)
        {
            if(ans[i]>=ans[i+1])
            {
                return false;
            }
        }
        return true;
    }
};
/*
    //SC= O(1) OPTIMIZED..
    bool solve(TreeNode* root, long long mini, long long maxi)
    {
        if(!root)
        {
            return true;
        }
        if(root->val<=mini || root->val>=maxi)
        {
            return false;
        }
        return solve(root->left,mini,root->val) && solve(root->right,root->val,maxi);
    }
    bool isValidBST(TreeNode* root) 
    {
        if(!root)
        {
            return true;
        }
        long long mini= LLONG_MIN;
        long long maxi= LLONG_MAX;
        return solve(root,mini,maxi);
    }
*/