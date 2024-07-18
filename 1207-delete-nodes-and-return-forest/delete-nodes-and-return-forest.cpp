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
class Solution 
{
public:
    vector<TreeNode*>ans;
    void dfs(TreeNode* root, unordered_set<int>&st, bool flag)
    {
        if(!root)
        {
            return;
        }
        if(st.find(root->val)!=st.end())
        {
            dfs(root->left,st,true);
            dfs(root->right,st,true);
        }
        else
        {
            if(flag)
            {
                ans.push_back(root);
            }
            TreeNode* leftnode= root->left;
            if(root->left)
            {
                if(st.find(root->left->val)!=st.end())
                {
                    root->left=NULL;
                }
            }
            TreeNode* rightnode= root->right;
            if(root->right)
            {
                if(st.find(root->right->val)!=st.end())
                {
                    root->right=NULL;
                }
            }
            dfs(leftnode,st,false);
            dfs(rightnode,st,false);
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) 
    {
        unordered_set<int>st(del.begin(),del.end());
   
        dfs(root,st,true);//initially true as we also needed root node if it is not in st
        //(that will automatically handled by dfs function)

        return ans;
    }
};