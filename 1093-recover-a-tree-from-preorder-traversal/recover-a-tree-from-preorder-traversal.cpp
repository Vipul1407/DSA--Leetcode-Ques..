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
    TreeNode* solve(string &str, int &i, int depth)
    {
        if(i>=str.size())
        {
            return NULL;
        }
        int j=i;
        while(j<str.size() && str[j]=='-')
        {
            j++;
        }
        int dash= j-i;
        if(dash!=depth)
        {
            return NULL;
        }
        i+=dash;
        int num=0;
        while(i<str.size() && isdigit(str[i]))
        {
            num= (num*10)+ (str[i]-'0');
            i++;
        }
        TreeNode* root= new TreeNode(num);
        root->left= solve(str,i,depth+1);
        root->right= solve(str,i,depth+1);
        return root;
    }
    TreeNode* recoverFromPreorder(string str) 
    {
        int i=0;
        return solve(str,i,0);
    }
};