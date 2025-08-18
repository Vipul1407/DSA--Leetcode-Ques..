class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int n= nums.size();
        int l=0;
        int r= n-1;   
        int ans= INT_MAX;
        while(l<=r)
        {
            int mid= l+(r-l)/2;
            //OPTIMIZATION..
            //complete array is sorted..
            if(nums[l]<=nums[r])
            {
                ans= min(ans,nums[l]);
                break;
            }
            //l to mid is sorted..(left part sorted)
            //go to right..
            if(nums[l]<=nums[mid])
            {
                ans= min(ans,nums[l]);
                l= mid+1;
            }
            //mid to r is sorted..(right part sorted)
            //go to left..
            else if(nums[mid]<=nums[r])
            {
                ans= min(ans,nums[mid]);
                r= mid-1;
            }
        }
        return ans;
    }
};