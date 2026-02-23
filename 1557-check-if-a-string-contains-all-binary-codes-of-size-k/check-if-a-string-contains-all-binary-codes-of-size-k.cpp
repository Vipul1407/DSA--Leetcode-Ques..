class Solution {
public:
    bool hasAllCodes(string s, int k) 
    {
        unordered_set<string>mp;
        int n= s.size();
        int cnt= (1<<k);
        for(int i=k;i<=n;i++)
        {
            string str= s.substr(i-k,k);
            if(!mp.count(str))
            {
                mp.insert(str);
                cnt--;
            }
            if(cnt==0)
            {
                return true;
            }
        }
        return cnt==0;
    }
};