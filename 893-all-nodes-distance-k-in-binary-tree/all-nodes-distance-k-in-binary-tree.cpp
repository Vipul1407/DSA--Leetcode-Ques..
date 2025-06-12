/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findparent(TreeNode* root, unordered_map<TreeNode*,TreeNode*>&mp)
    {
        if(!root)
        {
            return;
        }
        if(root->left)
        {
            mp[root->left]= root;
            findparent(root->left,mp);
        }
        if(root->right)
        {
            mp[root->right]= root;
            findparent(root->right,mp);
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* tar, int k) 
    {
        unordered_map<TreeNode*,TreeNode*>mp;
        findparent(root,mp);
        unordered_set<int>st;
        queue<TreeNode*>q;
        q.push(tar);
        st.insert(tar->val);
        while(!q.empty())
        {
            if(k==0)
            {
                break;
            }
            int size= q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* curr= q.front();
                q.pop();

                //left
                if(curr->left && st.find(curr->left->val)==st.end())
                {
                    q.push(curr->left);
                    st.insert(curr->left->val);
                }
                //right 
                if(curr->right && st.find(curr->right->val)==st.end())
                {
                    q.push(curr->right);
                    st.insert(curr->right->val);
                }
                //parent
                if(mp.count(curr) && st.find(mp[curr]->val)==st.end())
                {
                    q.push(mp[curr]);
                    st.insert(mp[curr]->val);
                }
            }
            k--;
        }
        vector<int>ans;
        while(!q.empty())
        {
            ans.push_back(q.front()->val);
            q.pop();
        }
        return ans;
    }
};