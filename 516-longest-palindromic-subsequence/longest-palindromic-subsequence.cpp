class Solution {
public:

    //same as longest common subsequence with s1= s and s2= rev(s)
    int longestPalindromeSubseq(string s) 
    {
        int n= s.length();
        string rev= s;
        reverse(rev.begin(),rev.end());
        vector<int>curr(n+1,0);
        vector<int>next(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(s[i]==rev[j])
                {
                    curr[j]= 1+next[j+1];
                }
                else
                {
                    curr[j]= max(next[j],curr[j+1]);
                }
            }
            next=curr;
        }
        return next[0];
    }
};