class Solution {
public:
    //Wrong ans in case like of 0 and (1/2)=0 
    int countSubarrays(vector<int>& nums) 
    {
        int n= nums.size();
        int cnt=0;
        for(int i=1;i<n-1;i++)
        {
            if((float)nums[i-1]+nums[i+1] == (float)nums[i]/2)
            {
                cnt++;
            }
        }
        return cnt;
    }
};