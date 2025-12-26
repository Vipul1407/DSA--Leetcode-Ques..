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
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>>ans;
        map<pair<int,int>,vector<int>>mp;
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});

        while(q.size())
        {
            int n= q.size();
            while(n--)
            {
                int row= q.front().second.first;
                int col= q.front().second.second;
                auto top= q.front().first;
                mp[{row,col}].push_back(top->val);
                q.pop();

                if(top->left)
                {
                    q.push({top->left,{row+1,col-1}});
                }
                if(top->right)
                {
                    q.push({top->right,{row+1,col+1}});
                }
            }
        }
        map<int,vector<int>>colmp;
        for(auto i:mp)
        {
            vector<int>temp= i.second;
            sort(begin(temp),end(temp));
            int col= i.first.second;
            for(auto i:temp)
            {
                colmp[col].push_back(i);
            }
        }
        for(auto i:colmp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //DFS..
    void dfs(TreeNode* root, int row, int col, map<pair<int,int>,vector<int>>&mp)
    {
        if(!root)
        {
            return;
        }
        mp[{row,col}].push_back(root->val);
        dfs(root->left,row+1,col-1,mp);
        dfs(root->right,row+1,col+1,mp);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) 
    {
        vector<vector<int>>ans;
        //ordered map..
        map<pair<int,int>,vector<int>>mp;
        //root is at vertical level i=0
        dfs(root,0,0,mp);

        map<int,vector<int>>colmp;
        for(auto i:mp)
        {
            int col= i.first.second;
            vector<int>temp= i.second;
            sort(begin(temp),end(temp));
            for(auto i:temp)
            {
                colmp[col].push_back(i);
            }
        }
        for(auto i:colmp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
*/