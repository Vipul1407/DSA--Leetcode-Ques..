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
    TreeNode* replaceValueInTree(TreeNode* root) 
    {
        queue<TreeNode*>q;
        q.push(root);
        int currsum=root->val;//curr level sum
        while(q.size())
        {
            int n= q.size();
            int nextsum=0;//next level sum
            while(n--)
            {
                TreeNode* temp= q.front();
                q.pop();
                temp->val= currsum-temp->val;//becoz temp contains sum of its siblings

                int sibling= temp->left? temp->left->val:0;
                sibling+= temp->right? temp->right->val:0;

                if(temp->left)
                {
                    nextsum+= temp->left->val;
                    temp->left->val= sibling;
                    //q me push krenge updated currsum-sibling
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    nextsum+= temp->right->val;
                    temp->right->val=sibling;
                    //q me push krenge updated currsum-sibling
                    q.push(temp->right);
                }
            }
            currsum=nextsum;//for next level sum..
        }
        return root;
    }
};