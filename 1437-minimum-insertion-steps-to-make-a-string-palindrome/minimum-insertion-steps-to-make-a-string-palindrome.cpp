class Solution {
public:
    
    //DIRECTLY SAME AS LONGEST COMMOM SUBSEQUENCE....
    int minInsertions(string s)
    {
        int n= s.length();
        string rev=s;
        reverse(rev.begin(),rev.end());
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s[i]==rev[j])
                {
                    dp[i][j]= 1+ dp[i+1][j+1];
                }
                else 
                {
                    dp[i][j]= max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        //to get min operations..
        //becoz dp[0][0] is storing the longest common palindromic subsequence length so n- this will give the min insertion..
        return n-dp[0][0];
    }
};