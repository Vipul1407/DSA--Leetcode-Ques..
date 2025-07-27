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
    //Simple BFS.. Without level order
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int curr=-1;

        while(q.size())
        {
            curr= q.front()->val;
            auto top= q.front();
            q.pop();

            //first push right... then left 
            if(top->right)
            {
                q.push(top->right);
            }
            if(top->left)
            {
                q.push(top->left);
            }
        }
        return curr;
    }
};
/*
    //METHOD-1
    //Level order traversal..
    int findBottomLeftValue(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int ans=-1;

        while(q.size())
        {
            int size= q.size();
            for(int i=0;i<size;i++)
            {
                if(i==0)
                {
                    ans= q.front()->val;
                }
                auto top= q.front();
                q.pop();
                if(top->left)
                {
                    q.push(top->left);
                }
                if(top->right)
                {
                    q.push(top->right);
                }
            }
        }
        return ans;
    }
*/