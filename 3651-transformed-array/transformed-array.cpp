class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans(n,0);
        for(int i=0;i<n;i++)
        {
            int move= nums[i];
            if(move<0)
            {
                move= abs(move)%n;
                ans[i]= nums[((i-move)%n+n)%n];
            }
            else
            {
                move= (move%n);
                ans[i]= nums[(i+move)%n];
            }
        }
        return ans;
    }
};