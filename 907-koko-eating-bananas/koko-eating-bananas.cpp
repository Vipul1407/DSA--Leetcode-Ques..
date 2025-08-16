class Solution {
public:
    bool possi(vector<int>& piles, int h, int mid)
    {
        int cnt=0;
        for(auto i:piles)
        {
            cnt+= i/mid+(i%mid!=0);
            if(cnt>h)
            {
                return false;
            }
        }
        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) 
    {
        int l=1;
        int r= *max_element(begin(piles),end(piles));
        int ans= r;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(possi(piles,h,mid))
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