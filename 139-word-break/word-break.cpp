class Solution {
public:
    bool solve(int i,string &s,unordered_set<string>&st,vector<int>&dp)
    {
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        if(i>=s.size())
        {
            return true;
        }
        if(st.find(s)!=st.end())
        {
            return true;
        }
        for(int len=0;len<s.size();len++)
        {
            string temp= s.substr(i,len);
            //curr string mil gyi and aage ke recursion se bhi all remaining strings mili then return true
            if(st.find(temp)!=st.end() && solve(i+len,s,st,dp))
            {
                return dp[i]= true;
            }
        }
        return dp[i]= false;
    }
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n= s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        vector<int>dp(n+1,-1);
        return solve(0,s,st,dp);
    }
};