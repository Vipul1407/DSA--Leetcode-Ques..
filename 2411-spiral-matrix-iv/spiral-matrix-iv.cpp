/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<vector<int>>mat(m,vector<int>(n,-1));
        int left=0;
        int right=n-1;
        int top=0;
        int down=m-1;
        while(top<=down && left<=right)
        {
            //going right..
            for(int i=left;i<=right;i++)
            {
                mat[top][i]= head->val;
                if(head->next)
                {
                    head=head->next;
                }
                else
                {
                    return mat;
                }
            }
            top++;

            //going down..
            for(int i=top;i<=down;i++)
            {
                mat[i][right]= head->val;
                if(head->next)
                {
                    head=head->next;
                }
                else
                {
                    return mat;
                }
            }
            right--;

            //going left..
            if(top<=down)
            {
                for(int i=right;i>=left;i--)
                {
                    mat[down][i]= head->val;
                    if(head->next)
                    {
                        head=head->next;
                    }
                    else
                    {
                        return mat;
                    }
                }
                down--;
            }

            //going up..
            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                    mat[i][left]= head->val;
                    if(head->next)
                    {
                        head=head->next;
                    }
                    else
                    {
                        return mat;
                    }
                }
                left++;
            }
        }
        return mat;
    }
};