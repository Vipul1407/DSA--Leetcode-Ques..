class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) 
    {
        int m= str1.size();
        int n= str2.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,0));

        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(str1[i]==str2[j])
                {
                    dp[i][j]= 1+dp[i+1][j+1];
                }
                else
                {
                    dp[i][j]= max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        //ans will be stored at 0,0 so starting i,j from 0..
        int i=0;
        int j=0;
        string ans="";
        while(i<m && j<n)
        {
            if(str1[i]==str2[j])
            {
                ans+= str1[i];
                i++;j++;
            }
            //jha se max common elngth milri h usko lenge ans me..
            else if(dp[i+1][j]>=dp[i][j+1])
            {
                ans+= str1[i];
                i++;
            }
            else
            {
                ans+= str2[j];
                j++;
            }
        }
        while(i<m)
        {
            ans+= str1[i++];
        }
        while(j<n)
        {
            ans+= str2[j++];
        }
        return ans;
    }
};