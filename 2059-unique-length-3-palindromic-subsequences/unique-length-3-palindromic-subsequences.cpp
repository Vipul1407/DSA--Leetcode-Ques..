class Solution {
public:
    int countPalindromicSubsequence(string s) 
    {
        int n= s.size();
        unordered_map<char,pair<int,int>>mp;
        for(int i=0;i<n;i++)
        {
            //char ni mila map me..
            //map me daal start,ending index..
            if(mp.find(s[i])==mp.end())
            {
                mp[s[i]]={i,i};
            }
            //phle se map me h to update kr bss ending element..
            else
            {
                mp[s[i]].second=i;
            }
        }
        int cnt=0;
        for(auto i:mp)
        {
            if(i.second.first==i.second.second)
            {
                continue;
            }
            unordered_set<int>st;
            int l= i.second.first;
            int r= i.second.second;
            //finding unique element b/w the range..
            for(int k=l+1;k<r;k++)
            {
                st.insert(s[k]);
            }
            cnt+= st.size();
        }
        return cnt;
    }
};