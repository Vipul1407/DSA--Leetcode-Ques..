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
};