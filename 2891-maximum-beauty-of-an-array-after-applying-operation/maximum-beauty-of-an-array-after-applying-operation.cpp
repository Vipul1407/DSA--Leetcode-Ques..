class Solution {
public:
    int binarys(vector<int>& nums,int idx,int k)
    {
        int val= nums[idx]+2*k;
        int l= idx;
        int r= nums.size()-1;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(nums[mid]<=val)
            {
                l= mid+1;//to get large stopping index
            }
            else 
            {
                r= mid-1;//to find valid index
            }
        }
        return r-idx+1;//length of subsequence..
    }
    int maximumBeauty(vector<int>& nums, int k) 
    {
        //(x-k,x+k), (y-k,y+k)
        //for overlapping--> y-k<=x+k --> (y<=x+2k)
        sort(nums.begin(),nums.end());
        int ans=0;
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            ans= max(ans,binarys(nums,i,k));
        }
        return ans;
    }
};