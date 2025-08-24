class Solution {
public:
    //Slding Window==> Asked in Salescode.ai OA
    int longestOnes(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int l=0,r=0,ans=0;
        while(r<n)
        {
            if(nums[r]==0)
            {
                k--;
            }
            while(l<r && k<0)
            {
                if(nums[l]==0)
                {
                    k++;
                }
                l++;
            }
            if(k>=0)
            {
                ans= max(ans,r-l+1);
            }
            r++;
        }
        return ans;
    }
};