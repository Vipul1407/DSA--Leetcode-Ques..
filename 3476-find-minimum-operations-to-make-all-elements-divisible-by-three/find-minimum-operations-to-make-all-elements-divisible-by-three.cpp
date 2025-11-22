class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int cnt=0;
        int n=nums.size();
        for(auto i:nums)
        {
            cnt+=min(i%3,3-i%3);
        }
        return cnt;
    }
};