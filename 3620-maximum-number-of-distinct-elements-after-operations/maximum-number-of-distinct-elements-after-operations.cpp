class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int ans=0;
        int demand= INT_MIN;
        sort(begin(nums),end(nums));
        for(auto i:nums)
        {
            int low= i-k;
            int high= i+k;
            if(demand<low)
            {
                demand= low;
                ans++;
            }
            else if(demand<high)
            {
                demand++;
                ans++;
            }
        }
        return ans;
    }
};