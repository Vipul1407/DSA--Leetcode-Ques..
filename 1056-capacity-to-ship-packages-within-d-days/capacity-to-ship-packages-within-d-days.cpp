class Solution {
public:
    bool possi(vector<int>& weights, int days, long long &mid)
    {
        int cnt=1;
        long long prefix=0;
        int n= weights.size();
        int idx=0;
        
        while(idx<n)
        {
            if(prefix+weights[idx]<=mid)
            {
                prefix+= weights[idx++];
            }
            else
            {
                cnt++;
                prefix=0;
            }
            if(idx>=n)
            {
                return cnt<=days;
            }
        }
        return cnt<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        long long l= *max_element(begin(weights),end(weights));
        long long r= accumulate(begin(weights),end(weights),0LL);
        long long ans= r;
        while(l<=r)
        {
            long long mid= l+(r-l)/2;
            if(possi(weights,days,mid))
            {
                ans= mid;
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return (int)ans;
    }
};