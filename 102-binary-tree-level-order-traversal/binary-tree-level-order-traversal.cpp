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
    //DFS---------------->
    void solve(TreeNode* root, int level, vector<vector<int>>&ans)
    {
        if(!root)
        {
            return;
        }
        if(level==ans.size())
        {
            ans.push_back({});
        }
        ans[level].push_back(root->val);
        solve(root->left,level+1,ans);
        solve(root->right,level+1,ans);
    }
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
        vector<vector<int>>ans;
        int level=0;//assuming root at level=0
        solve(root,level,ans);
        return ans;
    }
};

//BFS--------------->
/*
// METHOD-1
// USING QUEUE
// BEATS 26%
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);
    q.push(NULL);
    vector<int> vec;

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            ans.push_back(vec);
            vec.clear();
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            vec.push_back(temp->val);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
    return ans;
}

// METHOD-2
//  BEATS 88%
vector<vector<int>> levelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (root == NULL)
    {
        return ans;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        vector<int> vec;
        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            vec.push_back(temp->val);
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
            q.pop();
        }
        ans.push_back(vec);
    }
    return ans;
}
*/