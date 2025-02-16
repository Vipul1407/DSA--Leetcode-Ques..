class Solution {
public:
    typedef long long ll;
    int minOperations(vector<int>& nums, int k)
    {
        priority_queue<ll,vector<ll>,greater<ll>>pq(nums.begin(),nums.end());
        int ans=0;
        while(pq.size()>1)
        {
            auto x= pq.top();
            if(x>=k)
            {
                return ans;
            }
            pq.pop();
            auto y= pq.top();
            pq.pop();
            pq.push(min(x,y)*2+max(x,y));
            ans++;
        }
        return ans;
    }
};