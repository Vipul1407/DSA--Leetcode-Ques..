class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) 
    {
        int n= words.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            string sub= words[i];
            for(int j=i+1;j<n;j++)
            {
                string full= words[j]; 
                if(sub.size()>full.size())
                {
                    continue;
                }
                bool pref= full.substr(0,sub.length())==sub;
                if(pref)
                {
                    bool suffix= full.substr(full.length()-sub.length(),sub.length())==sub;
                    if(suffix==true)
                    {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};