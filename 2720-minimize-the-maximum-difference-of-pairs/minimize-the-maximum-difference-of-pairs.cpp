class Solution {
public:
    bool possible(vector<int>& nums, int p, int diff)
    {
        int cnt=0;
        int n= nums.size();
        for(int i=1;i<n;i+=2)
        {
            if(nums[i]-nums[i-1]<=diff)
            {
                cnt++;
                if(cnt>=p)
                {
                    return true;
                }
            }
            else
            {
                i--;
            }
        }
        return cnt>=p;
    }
    int minimizeMax(vector<int>& nums, int p) 
    {
        int n= nums.size();
        int ans= INT_MAX;
        sort(nums.begin(),nums.end());
        int l=0;
        int r= nums[n-1]-nums[0];
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(possible(nums,p,mid))
            {
                ans= mid;
                r= mid-1;//to get min ans..
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};