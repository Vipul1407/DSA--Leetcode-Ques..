class Solution {
public:
    int maximumLength(string s) 
    {
        int n= s.length();
        vector<vector<int>>vec(26,vector<int>(n+1,0));
        char ch= s[0];
        int cnt=0;
        for(auto i:s)
        {
            if(ch==i)
            {
                cnt++;
            }
            else
            {
                cnt=1;
                ch=i;
            }
            vec[i-'a'][cnt]++;
        }
        int maxlen= -1;
        for(int row=0;row<26;row++)
        {
            int sum=0;
            for(int col=n;col>=1;col--)
            {
                sum+= vec[row][col];
                if(sum>=3)
                {
                    maxlen= max(maxlen,col);
                    break;
                }
            }
        }
        return maxlen;
    }
};