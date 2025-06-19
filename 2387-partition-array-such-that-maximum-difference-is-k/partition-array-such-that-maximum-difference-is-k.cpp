class Solution {
public:
    int partitionArray(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int ans=1;
        int s=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            if(nums[i]-nums[s]>k)
            {
                s= i;
                ans++;
            }
        }
        return ans;
    }
};