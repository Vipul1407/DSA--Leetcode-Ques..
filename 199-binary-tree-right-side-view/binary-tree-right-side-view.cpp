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
    //DFS..
    void solve(TreeNode* root, vector<int>&ans, int level)
    {
        if(root==NULL)
        {
            return;
        }
        if(level==ans.size())
        {
            ans.push_back(root->val);
        }
        //first solve for right subtree..
        solve(root->right,ans,level+1);
        //then left subtree..
        solve(root->left,ans,level+1);
    }
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        solve(root,ans,0);
        return ans;
    }
};