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
    //Not Taking &cnt in fun call making int return type....
    //will not call maxi by using & as we have to track maxi for seperate paths..
    int solve(TreeNode* root, int maxi) 
    {
        if(!root)
        {
            return 0;
        }
        if(root->val>=maxi)
        {
            maxi= max(maxi,root->val);
            return 1+ solve(root->left,maxi)+ solve(root->right,maxi);
        }
        maxi= max(maxi,root->val);
        return 0+ solve(root->left,maxi)+ solve(root->right,maxi);
    }
    int goodNodes(TreeNode* root) 
    {
        if(!root)
        {
            return 0;
        }
        int maxi= root->val;
        return solve(root,maxi);
    }
};
/*
    //METHOD-1
    //Taking &cnt in fun call....
    //will not call maxi by using & as we have to track maxi for seperate paths..

    void solve(TreeNode* root, int &cnt, int maxi)
    {
        if(!root){
            return;
        }
        if(root->val>=maxi)
        {
            cnt++;
        }
        maxi= max(maxi,root->val);
        solve(root->left,cnt,maxi);
        solve(root->right,cnt,maxi);
    }
    int goodNodes(TreeNode* root) 
    {
        int cnt=0;
        solve(root,cnt,root->val);
        return cnt;
    }
*/