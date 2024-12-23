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
    //DFS..
    void dfs(TreeNode* root, int level, vector<vector<int>>&ans)
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
        dfs(root->left,level+1,ans);
        dfs(root->right,level+1,ans);
    }
    int minimumOperations(TreeNode* root) 
    {
        int cnt=0;
        vector<vector<int>>ans;
        int level=0;
        dfs(root,level,ans);
        for(vector<int>vec: ans)
        {
            unordered_map<int,int>mp;
            vector<int>sorted= vec;
            sort(sorted.begin(),sorted.end());
            int m= sorted.size();
            for(int i=0;i<m;i++)
            {
                mp[vec[i]]=i;
            }
            for(int i=0;i<m;i++)
            {
                if(vec[i]!=sorted[i])
                {
                    int j= mp[sorted[i]];
                    mp[vec[i]]=j;
                    mp[vec[j]]=i;
                    swap(vec[i],vec[j]);
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

/*
// METHOD-1
// BFS..
// BEATS 40%
void solve(TreeNode *root, int &cnt)
{
    if (!root)
    {
        return;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> ans;
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            auto temp = q.front();
            ans.push_back(temp->val);
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
        // here ans contains all nodes at a level
        vector<int> sorted = ans;
        sort(sorted.begin(), sorted.end());
        unordered_map<int, int> mp;
        int m = ans.size();
        for (int i = 0; i < m; i++)
        {
            mp[ans[i]] = i;
        }
        for (int i = 0; i < m; i++)
        {
            if (ans[i] != sorted[i])
            {
                int j = mp[sorted[i]];
                // updating the map indexes...
                mp[ans[i]] = j;
                mp[ans[j]] = i;
                // swapping after that..
                swap(ans[i], ans[j]);
                cnt++;
            }
        }
    }
}
int minimumOperations(TreeNode *root)
{
    int cnt = 0;
    solve(root, cnt);
    return cnt;
}
*/