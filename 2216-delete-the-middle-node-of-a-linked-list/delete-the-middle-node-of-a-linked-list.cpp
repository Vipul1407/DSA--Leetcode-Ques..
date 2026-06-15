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
    ListNode* deleteMiddle(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return NULL;
        }
        ListNode*curr=head;
        int len=0;
        while(curr)
        {
            len++;
            curr=curr->next;
        }
        int n=(len/2)+1;
        curr=head;
        ListNode* prev=NULL;
        int cnt=0;
        while(curr && cnt<n-1)
        {
            prev=curr;
            curr=curr->next;
            cnt++;
        }
        prev->next=curr->next;
        return head;
    }
};