class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        int cnt=0;
        unordered_set<char>st(allowed.begin(),allowed.end());
        int flag=0;
        for(auto i:words)
        {
            for(auto j:i)
            {
                //char ni mila..
                if(st.find(j)==st.end())
                {
                    flag= 1;
                    break;
                }
            }
            if(flag==0)
            {
                cnt++;
            }
            flag=0;
        }    
        return cnt;
    }
};