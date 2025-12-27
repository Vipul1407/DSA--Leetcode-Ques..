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
    //STORING IN MAP + FINDING STARTNODE ADDRESS..
    void dfs(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp, TreeNode* &startingnode, int &start)
    {
        if(!root)
        {
            return;
        }
        //do not return so that mp gets completed fully..
        if(root->val==start)
        {
            startingnode= root;
        }
        if(root->left)
        {
            mp[root->left]= root;
            dfs(root->left,mp,startingnode,start);
        }
        if(root->right)
        {
            mp[root->right]= root;
            dfs(root->right,mp,startingnode,start);
        }
    }
    int amountOfTime(TreeNode* root, int start) 
    {
        unordered_map<TreeNode*,TreeNode*>mp;
        TreeNode* startingnode= NULL;

        dfs(root,mp,startingnode,start);
        queue<pair<TreeNode*,int>>q;
        unordered_set<int>st;
        int ans= INT_MIN;

        q.push({startingnode,0});
        st.insert(start);
        while(!q.empty())
        {
            int n= q.size();
            while(n--)
            {
                auto top= q.front().first;
                int time= q.front().second;
                ans= max(ans,time);
                q.pop();

                if(top->left && st.find(top->left->val)==st.end())
                {
                    q.push({top->left,time+1});
                    st.insert(top->left->val);
                }
                if(top->right && st.find(top->right->val)==st.end())
                {
                    q.push({top->right,time+1});
                    st.insert(top->right->val);
                }
                if(mp[top] && st.find(mp[top]->val)==st.end())
                {
                    q.push({mp[top],time+1});
                    st.insert(mp[top]->val);
                }
            }
        }
        return ans;
    }
};