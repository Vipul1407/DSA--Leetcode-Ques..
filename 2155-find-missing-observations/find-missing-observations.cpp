class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) 
    {
        long long sum=0;
        for(auto i:rolls)
        {
            sum+=i;
        }
        int size= rolls.size();
        long long val= mean*(size+n)-sum;
        if(val> n*6 || val< n)
        {
            return {};
        }
        vector<int>ans(n,val/n);

        int rem= val%n;
        for(int i=0;i<rem;i++)
        {
            ans[i]++;
        }
        return ans;
    }
};