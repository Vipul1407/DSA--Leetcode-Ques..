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
class FindElements {
public:
    //METHOD-1
    //USING DFS..
    TreeNode*root=NULL;
    void dfs(TreeNode* root, int x)
    {
        if(!root)
        {
            return;
        }
        root->val= x;
        dfs(root->left,2*x+1);
        dfs(root->right,2*x+2);
    }
    FindElements(TreeNode* root) 
    {
        this->root= root;
        dfs(root,0);
    }
    bool search(TreeNode* root, int tar)
    {
        if(!root)
        {
            return false;
        }
        if(root->val==tar)
        {
            return true;
        }
        return search(root->left,tar) || search(root->right,tar);
    }
    bool find(int tar) 
    {
        return search(root,tar);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */