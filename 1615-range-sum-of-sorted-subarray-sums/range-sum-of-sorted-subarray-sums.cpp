class Solution {
public:
    #define MOD 1000000007
    int rangeSum(vector<int>& nums, int n, int left, int right) 
    {
        vector<int>vec;
        for(int i=0;i<n;i++)
        {
            int sum=0;
            for(int j=i;j<n;j++)
            {
                sum= (sum+nums[j])%MOD;
                vec.push_back(sum);
            }
        }
        sort(vec.begin(),vec.end());
        int ans=0;
        //becoz left and right have 1-based indexing..
        for(int i=left-1;i<=right-1;i++)
        {
            ans= (ans+vec[i])%MOD;
        }
        return ans;
    }
};