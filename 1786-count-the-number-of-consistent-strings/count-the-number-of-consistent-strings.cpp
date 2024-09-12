class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) 
    {
        vector<int>vec(26,0);
        int cnt=0;
        for(auto i:allowed)
        {
            vec[i-'a']++;
        }    
        int flag=0;
        for(auto i:words)
        {
            for(auto j:i)
            {
                if(vec[j-'a']==0)
                {
                    flag=1;
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