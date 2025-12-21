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
    int count(ListNode* head)
    {
        int cnt=0;
        while(head!=NULL)
        {
            cnt++;
            head= head->next;
        }
        return cnt;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        int len= count(head);
        if(!head || len<k)
        {
            return head;
        }
        //step1- reverse k nodes...
        ListNode* prev= NULL;
        ListNode* curr= head;
        ListNode* forward= NULL;
        int cnt=0;
        while(curr!=NULL && cnt<k)
        {
            forward= curr->next;
            curr->next= prev;
            prev= curr;
            curr= forward;
            cnt++;
        }
        if(forward!=NULL)
        {
            head->next= reverseKGroup(forward,k);
        }
        return prev;
    }
};