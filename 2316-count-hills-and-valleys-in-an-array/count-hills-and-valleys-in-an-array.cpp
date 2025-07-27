class Solution {
public:
    //METHOD-1
    //BRUTE FORCE...
    int countHillValley(vector<int>& nums) 
    {
        int n= nums.size();
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            //it is necessary to prevent counting duplicates...
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            int ele= nums[i];
            int j=i-1;
            while(j>=0 && nums[j]==ele)
            {
                j--;
            }
            int k=i+1;
            while(k<n && nums[k]==ele)
            {
                k++;
            }
            if(j>=0 && k<n)
            {
                if(nums[j]<ele && nums[k]<ele)
                {
                    ans++;
                }
                else if(nums[j]>ele && nums[k]>ele)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};  