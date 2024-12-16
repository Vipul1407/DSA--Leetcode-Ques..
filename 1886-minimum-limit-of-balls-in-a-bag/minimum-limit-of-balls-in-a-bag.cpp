class Solution {
public:
    bool possi(vector<int>& nums, int k, int mid)
    {
        int op=0;
        for(auto i:nums)
        {
            op+= i/mid;
            if(i%mid==0)
            {
                op--;
            }
        }
        return op<=k;
    }
    int minimumSize(vector<int>& nums, int k) 
    {
        int l=1;
        int r= *max_element(nums.begin(),nums.end());
        int ans=r;
        while(l<=r)    
        {
            int mid= l+(r-l)/2;
            if(possi(nums,k,mid))
            {
                ans= mid;
                r= mid-1;//to get min ans
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};