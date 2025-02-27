class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int n= nums.size();
        int i=0;
        int j=0;
        int sum=0;
        int ans=n+1;
        while(j<n)
        {
            sum+= nums[j];
            while(sum>=target)
            {
                ans= min(ans,j-i+1);
                sum-= nums[i];
                i++;
            }
            j++;
        }
        return ans==n+1? 0:ans;
    }
};