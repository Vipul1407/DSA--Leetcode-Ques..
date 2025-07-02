class Solution {
public:
    //METHOD-2
    //BFS...
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n= s.size();
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        queue<int>q;
        vector<int>vis(n+1,0);
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            auto idx= q.front();
            q.pop();
            for(int end=idx+1; end<=n; end++)
            {
                if(vis[end])
                {
                    continue;
                }
                string temp= s.substr(idx,end-idx);
                if(st.find(temp)!=st.end())
                {
                    if(end==n)
                    {
                        return true;
                    }
                    if(!vis[end])
                    {
                        q.push(end);
                        vis[end]=1;
                    }
                }
            }
        }
        return false;
    }
};

/*
    //METHOD-1
    //DFS...
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
        //for(int len=0;len<s.size();len++)
        for(int len=0;len+i<=s.size();len++)
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
*/