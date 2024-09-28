class Solution {
public:
    int minExtraChar(string s, vector<string>& dict) 
    {
        unordered_set<string>st(dict.begin(),dict.end());
        int n= s.length();
        vector<int>dp(n+1,0);
        for(int i= n-1;i>=0;i--)
        {
            int result= 1+dp[i+1];
            for(int j=i;j<n;j++)
            {
                string curr= s.substr(i,j-i+1);
                if(st.find(curr)!=st.end())
                {
                    result= min(result, dp[j+1]);
                }
            }
            dp[i]=result;
        }
        return dp[0];
    }
};