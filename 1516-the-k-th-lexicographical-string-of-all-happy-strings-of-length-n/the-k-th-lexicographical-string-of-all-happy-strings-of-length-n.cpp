class Solution {
public:
    void solve(int &cnt, string str, string &ans, char prev, int n, int &k)
    {
        if(n==0)
        {
            cnt++;
            if(cnt==k)
            {
                ans= str;
            }
            return;
        }
        for(char ch='a';ch<='c';ch++)
        {
            if(prev==ch)
            {
                continue;
            }
            str.push_back(ch);
            solve(cnt,str,ans,ch,n-1,k);
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) 
    {
        string ans;
        int cnt=0;
        solve(cnt,"",ans,'*',n,k);
        return ans;
    }
};