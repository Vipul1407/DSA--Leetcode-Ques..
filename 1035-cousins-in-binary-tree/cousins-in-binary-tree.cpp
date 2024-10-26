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
    bool isCousins(TreeNode* root, int x, int y) 
    {
        
        queue<TreeNode*>q;
        q.push(root);
        bool foundx= false;
        bool foundy= false;
        while(q.size())
        {
            int size= q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* temp= q.front();
                q.pop();
                //return false if they are siblings
                if(temp->left && temp->right)
                {
                    if((temp->left->val==x && temp->right->val==y) || (temp->left->val==y && temp->right->val==x))
                    {
                        return false;
                    }
                }
                if(temp->val==x)
                {
                    foundx= true;
                }
                if(temp->val==y)
                {
                    foundy= true;
                }
                if(temp->left)
                {
                    q.push(temp->left);
                }
                if(temp->right)
                {
                    q.push(temp->right);
                }
            }
            //after doing for calc for level---
            //dono mil gye same level p and vo siblings ni h mtlb cousins h...
            if(foundx && foundy)
            {
                return true;
            }
            //agar koi ek mila bss same level pto return false kr..
            if(foundx || foundy)
            {
                return false;
            }
        }
        return false;
    }
};

/*
public class Solution {
    public int xd, xp, yd, yp;
    public void helper(TreeNode root, int x, int y, int parent, int depth){
        if(root!=null)
        {
            if(root.val==x){
                xd= depth;
                xp= parent;
            }
                
            if(root.val==y){
                yd=depth;
                yp=parent;
            }
            depth++;
            parent=root.val;
            helper(root.left,x,y,parent,depth);
            helper(root.right,x,y,parent,depth);
        }
    }
    public bool IsCousins(TreeNode root, int x, int y) {
        helper(root,x,y,0,1);
        if((xd==yd)&&(xp!=yp))
            return true;
        return false;
    }
}*/