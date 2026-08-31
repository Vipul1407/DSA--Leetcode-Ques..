class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* a=head;
        ListNode* b=head->next;
        ListNode* c=head->next->next;
        if(c==NULL) return {-1,-1};
        int idx=1;
        int fidx=-1;
        int sidx=-1;
        int f=-1;
        int s=-1;
        int mind=INT_MAX,maxd=-1;
        while(c)
        {
            if((b->val>a->val &&b->val>c->val) || (b->val<a->val &&b->val<c->val))
            {
                if(fidx==-1) fidx=idx;
                else sidx=idx;
                if(sidx!=-1)    maxd=max(maxd,sidx-fidx);
                f=s;
                s=idx;
                if(f!=-1)
                {
                    mind=min(mind,s-f);
                }
                
            }
            a=a->next;
            b=b->next;
            c=c->next;
            idx++;

        }
        if(sidx==-1|| f==-1) return {-1,-1};
        return {mind,maxd};
        
    }
};