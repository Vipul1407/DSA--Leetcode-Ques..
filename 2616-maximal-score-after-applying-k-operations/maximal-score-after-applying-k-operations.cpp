class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) 
    {
        priority_queue<int>pq;//max heap..
        long long ans=0;
        for(auto i:nums)
        {
            pq.push(i);
        }
        while(pq.size() && k>0)
        {
            ans+= pq.top();
            pq.push(ceil((double)pq.top()/3));
            pq.pop();
            k--;
        }
        return ans;
    }
};