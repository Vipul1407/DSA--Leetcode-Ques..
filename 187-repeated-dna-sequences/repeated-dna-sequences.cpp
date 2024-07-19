class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        int n=s.length();
        if(n<10)
        {
            return {};
        }
        unordered_map<string,int>mp;
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            string str= s.substr(i,10);
            mp[str]++;
            if(mp[str]==2)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};