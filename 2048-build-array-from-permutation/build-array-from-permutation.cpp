class Solution {
public:
    //METHOD-2
    //SC= O(1)
    vector<int> buildArray(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int replaced= nums[nums[i]]%n;
            ans[i]= replaced;
            nums[i]= nums[i]%n+ replaced*n;
        }
        return ans;
    }
};
/*
    //METHOD-1
    //SC= O(N)
    vector<int> buildArray(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            ans[i]= nums[nums[i]];
        }
        return ans;
    }
*/