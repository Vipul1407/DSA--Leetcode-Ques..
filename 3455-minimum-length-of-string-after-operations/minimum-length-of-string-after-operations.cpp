class Solution {
public:
    int minimumLength(string s) 
    {
        vector<int>vec(26,0);
        int ans=0;
        for(auto i:s)
        {
            vec[i-'a']++;
            if(vec[i-'a']==3)
            {
                vec[i-'a']-=2;
                ans+=2;
            }
        }    
        return s.size()-ans;
    }
};