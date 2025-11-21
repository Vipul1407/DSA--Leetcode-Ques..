class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        vector<int>first(26,-1);
        vector<int>last(26,-1);
        int n= s.size();
        for(int i=0;i<n;i++)
        {
            int ch= s[i];
            if(first[ch-'a']==-1)
            {
                first[ch-'a']=i;
            }
            last[ch-'a']=i;
        }
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(first[i]==-1)
            {
                continue;
            }
            unordered_set<char>st;
            for(int j= first[i]+1;j<last[i];j++)
            {
                st.insert(s[j]);
            }
            ans+= st.size();
        }
        return ans;
    }
};