class Solution {
public:
    int minimumLength(string s) 
    {
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
            if(vec[i-'a']==3)
            {
                vec[i-'a']-=2;
            }
        }    
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(vec[i]==0)
            {
                continue;
            }
            ans+= vec[i];
        }
        return ans;
    }
};