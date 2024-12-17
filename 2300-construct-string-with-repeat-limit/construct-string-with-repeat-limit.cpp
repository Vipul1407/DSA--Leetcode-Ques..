class Solution {
public:
    string repeatLimitedString(string s, int k) 
    {
        vector<int>vec(26,0);
        string ans="";
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        int i=25;
        while(i>=0)
        {
            if(vec[i]==0)
            {
                i--;
                continue;
            }
            int x= min(vec[i],k);
            vec[i]-=x;
            while(x--)
            {
                ans+= i+'a';
            }
            if(vec[i]>0)
            {
                int j=i-1;
                while(j>=0 && vec[j]==0)
                {
                    j--;
                }
                if(j<0)
                {
                    break;
                }
                if(vec[j]>0)
                {
                    ans+= j+'a';
                    vec[j]--;
                }
            }
        }
        return ans;
    }
};