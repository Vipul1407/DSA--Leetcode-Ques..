class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) 
    {
        long long ans=0;
        sort(rbegin(happiness),rend(happiness));
        int cnt=0;
        for(auto i:happiness)
        {
            if(k>0)
            {
                if(i-cnt<=0)
                {
                    return ans;
                }
                ans+= i-cnt;
                cnt++;
                k--;
            }
        }
        return ans;
    }
};