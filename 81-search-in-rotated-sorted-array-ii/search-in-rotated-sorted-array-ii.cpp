class Solution {
public:
    bool search(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int l=0,r=n-1;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            if(nums[mid]==k)
            {
                return true;
            }
            //skipping duplicates..
            if(nums[l]==nums[mid] && nums[mid]==nums[r])
            {
                l++;
                r--;
                continue;
            }
            //left half is sorted..
            //l to mid..
            if(nums[l]<=nums[mid])
            {
                if(nums[l]<=k && nums[mid]>=k)
                {
                    r= mid-1;
                }
                else
                {
                    l= mid+1;
                }
            }
            //right half is sorted..
            //mid to r..
            else
            {
                if(nums[mid]<=k && nums[r]>=k)
                {
                    l= mid+1;
                }
                else
                {
                    r= mid-1;
                }
            }
        }
        return false;
    }
};