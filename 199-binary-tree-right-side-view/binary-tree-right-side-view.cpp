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
    //BFS..
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int>ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int n=q.size();
            int val=0;
            for(int i=0;i<n;i++)
            {
                TreeNode* temp= q.front();
                val=temp->val;
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
                q.pop();
            }
            //pushing value after 1 level completed.. so that val contains rightmost last node processed
            ans.push_back(val);  
        }
        
        return ans;
    }
};
/*
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
*/