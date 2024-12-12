class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) 
    {
        priority_queue<int>pq;
        for(auto i:gifts)
        {
            pq.push(i);
        }
        long long sum=0;
        while(pq.size() && k>0)
        {
            int ele= pq.top();
            pq.pop();
            ele= sqrt(ele);
            if(ele>0)
            {
                pq.push(ele);
            }
            k--;
        }
        while(pq.size())
        {
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};