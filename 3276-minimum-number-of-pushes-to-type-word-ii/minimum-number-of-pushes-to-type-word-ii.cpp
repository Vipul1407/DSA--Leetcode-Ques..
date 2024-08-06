class Solution {
public:
    int minimumPushes(string word) 
    {
        vector<int>vec(26,0);
        for(auto i:word)
        {
            vec[i-'a']++;
        }
        sort(vec.rbegin(),vec.rend());
        int ans=0;
        for(int i=0;i<26;i++)
        {
            //adding 1 as index starting from
            ans+= vec[i]*(1+i/8);
        }
        return ans;
    }
};