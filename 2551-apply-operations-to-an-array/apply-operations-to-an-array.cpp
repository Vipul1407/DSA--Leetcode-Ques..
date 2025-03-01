class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                nums[i]*=2;
                nums[i+1]=0;
            }
        }
        int cnt=0;
        for(auto i:nums)
        {
            if(i!=0)
            {
                ans.push_back(i);
                cnt++;
            }
        }
        int len= n-cnt;
        while(len--)
        {
            ans.push_back(0);
        }
        return ans;
    }
};
/*
    {// METHOD-2
// USING IMPLACE SWAPPING
vector<int> applyOperations(vector<int> &nums)
{
    int n = nums.size();
    for (int i = 0; i < n - 1; i++)
    {
        if (nums[i] == nums[i + 1])
        {
            nums[i] *= 2;
            nums[i + 1] = 0;
        }
    }
    int i = 0; // find zero element
    int j = 0; // find non zero so that it can be swapped..
    while (j < n)
    {
        // i will remain at 0 element..
        if (nums[j] != 0)
        {
            swap(nums[i], nums[j]);
            i++;
        }
        j++;
    }
    return nums;
}
*/