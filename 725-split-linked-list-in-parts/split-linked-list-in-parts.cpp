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
    vector<ListNode*> splitListToParts(ListNode* head, int k) 
    {
        ListNode* curr= head;
        int len=0;
        while(curr)
        {
            len++;
            curr=curr->next;
        }
        vector<ListNode*>ans;
        if(k>=len)
        {
            curr=head;
            while(curr)
            {
                ans.push_back(curr);
                ListNode* temp= curr->next;
                curr->next=NULL;
                curr=temp;
                k--;
            }
            while(k>0)
            {
                ans.push_back(NULL);
                k--;
            }
        }
        else
        {
            vector<int>vec(k,len/k);
            int rem=len%k;
            for(int i=0;i<rem;i++)
            {
                vec[i]++;
            }
            curr=head;
            int i=0;
            while(curr)
            {
                ans.push_back(curr);
                for(int j=0;j<vec[i]-1;j++)
                {
                    curr=curr->next;
                }
                
                    ListNode* temp=curr->next;
                    curr->next=NULL;
                    curr= temp;
    
                i++;
            }
        }
        return ans;
    }
};