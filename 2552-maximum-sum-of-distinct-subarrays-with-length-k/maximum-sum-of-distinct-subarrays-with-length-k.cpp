class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) 
    {
        int n= nums.size();
        unordered_set<int>st;
        long long sum=0;
        long long maxsum=0;
        int r=0,l=0;
        while(r<n)
        {
            //if we found a element that is already present in set, then shrink the window until we have bo occurence of that left..
            while(st.find(nums[r])!=st.end())
            {
                sum-= nums[l];
                st.erase(nums[l]);
                l++;
            }
            st.insert(nums[r]);
            sum+= nums[r];
            //shrink window when size==k for making space for next element..
            if(r-l+1==k)
            {
                maxsum= max(maxsum,sum);
                st.erase(nums[l]);
                sum-= nums[l];
                l++;
            }
            r++;
        }
        return maxsum;
    }
};