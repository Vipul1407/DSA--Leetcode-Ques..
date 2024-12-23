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
    int cnt=0;
    void solve(TreeNode* root)
    {
        if(!root)
        {
            return;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            vector<int>ans;
            int n= q.size();
            for(int i=0;i<n;i++)
            {
                auto temp= q.front();
                ans.push_back(temp->val);
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
            //here ans contains all nodes at a level
            vector<int>sorted= ans;
            sort(sorted.begin(),sorted.end());
            unordered_map<int,int>mp;
            int m= ans.size();
            for(int i=0;i<m;i++)
            {
                mp[ans[i]]= i; 
            }
            for(int i=0;i<m;i++)
            {
                if(ans[i]!=sorted[i])
                {
                    int j= mp[sorted[i]];
                    //updating the map indexes...
                    mp[ans[i]]=j;
                    mp[ans[j]]=i;
                    //swapping after that..
                    swap(ans[i],ans[j]);
                    cnt++;
                }
            }
        }
    }
    int minimumOperations(TreeNode* root) 
    {
        solve(root);
        return cnt;
    }
};