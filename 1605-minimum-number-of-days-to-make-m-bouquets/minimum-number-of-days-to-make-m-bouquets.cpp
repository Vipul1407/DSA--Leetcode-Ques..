class Solution {
public:
    bool possi(vector<int>& bloomDay, int m, int k, int &mid)
    {
        int cnt=0;
        long long canform=0;
        for(auto i:bloomDay)
        {
            if(i<=mid)
            {
                cnt++;
                if(cnt==k)
                {
                    canform++;
                    cnt=0;
                }
            }
            else
            {
                cnt=0;
            }
            if(canform>=m)
            {
                return true;
            }
        }
        return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) 
    {
        int l= *min_element(begin(bloomDay),end(bloomDay));
        int r= *max_element(begin(bloomDay),end(bloomDay));
        int ans= -1;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(possi(bloomDay,m,k,mid))
            {
                ans= mid;
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};