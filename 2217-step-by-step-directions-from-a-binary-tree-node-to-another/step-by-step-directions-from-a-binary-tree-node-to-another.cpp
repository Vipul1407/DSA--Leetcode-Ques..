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
    TreeNode* lca(TreeNode* root, int s, int d) 
    {
        if(!root)
        {
            return NULL;
        }
        TreeNode* left= lca(root->left,s,d);
        TreeNode* right= lca(root->right,s,d);
        if(root->val==s || root->val==d || (left && right))
        {
            return root;
        }
        return left? left:right;
    }

    string storoot, dtoroot;
    void dfs(TreeNode* root, string& ans, int s, int d)
    {
        if(!root)
        {
            return;
        }

        if(root->val==s)
        {
            storoot= ans;
        }
        if(root->val==d)
        {
            dtoroot= ans;
        }
        ans.push_back('L');
        dfs(root->left,ans,s,d);
        ans.pop_back();

        ans.push_back('R');
        dfs(root->right,ans,s,d);
        ans.pop_back();
    }

    string getDirections(TreeNode* root, int s, int d) 
    {
        TreeNode* lcanode= lca(root,s,d);
        string ans="";
        //in dfs call our root= lca node
        dfs(lcanode,ans,s,d);
        for(auto &i:storoot)
        {
            i='U';
        }
        return storoot+ dtoroot;
    }
};