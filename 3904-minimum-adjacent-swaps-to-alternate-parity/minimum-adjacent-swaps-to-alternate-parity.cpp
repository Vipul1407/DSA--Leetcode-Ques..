class Solution {
public:
    int solve(vector<int>& nums, int val)
    {
        int ans=0,curr=0;
        int n= nums.size();

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==val)
            {
                //becoz we can only swap alternate elements..
                ans+= abs(i-curr);
                curr+=2;
            } 
        }
        return ans;
    }
    int minSwaps(vector<int>& nums) 
    {
        int n= nums.size();
        int odd=0,even=0;
        for(auto i:nums)
        {
            if(i%2==0)
            {
                even++;
            }
            else
            {
                odd++;
            }
        }    
        if(abs(odd-even)>1)
        {
            return -1;
        }
        if(even>odd)
        {
            //we will find even no at even index..
            return solve(nums,0);
        }
        else if(odd>even)
        {
            //we will find odd no at even index..
            return solve(nums,1);
        }
        else
        {
            return min(solve(nums,1),solve(nums,0));
        }
        return -1;
    }
};