class Solution {
public:
    int rec(int i,string s, unordered_set<string>&st, vector<int>&dp)
    {
        if(i>=s.length())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int result= 1+ rec(i+1,s,st,dp);
        for(int j=i;j<s.length();j++)
        {
            //forming a substring starting from i itself
            string curr= s.substr(i,j-i+1);
            if(st.find(curr)!=st.end())
            {
                result= min(result, rec(j+1,s,st,dp));
            }
        }
        return dp[i]=result;
    }
    int minExtraChar(string s, vector<string>& dict) 
    {
        unordered_set<string>st(dict.begin(),dict.end());
        vector<int>dp(s.length()+1,-1);
        return rec(0,s,st,dp);
    }
};