class Solution {
public:
    #define MOD 1000000007
    int rec(int i,int j,vector<string>& words, string &tar, vector<vector<long long>>&freq, vector<vector<long long>>&dp)
    {
        if(j>=tar.size())
        {
            return 1; 
        }
        if(i>=words[0].size())
        {
            return 0;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        long long notake= (rec(i+1,j,words,tar,freq,dp))%MOD;
        long long take= (freq[tar[j]-'a'][i]*rec(i+1,j+1,words,tar,freq,dp))%MOD;
        return dp[i][j]= (take+notake)%MOD;
    }
    int numWays(vector<string>& words, string tar) 
    {
        int n= words.size();
        int m= words[0].size();
        int k= tar.size();
        //to cnt freq of each char at each index for word[i] i.e internal size ..
        vector<vector<long long>>freq(26,vector<long long>(m,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                freq[words[i][j]-'a'][j]++;
            }
        }
        //i--> denoting internal dict word index..
        //j--> denoting tar index..
        vector<vector<long long>>dp(m+1,vector<long long>(k+1,-1));
        return rec(0,0,words,tar,freq,dp);
    }
};