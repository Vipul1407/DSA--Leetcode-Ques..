class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) 
    {
        int n=s.length();
        if(n<10)
        {
            return {};
        }
        unordered_set<string>st;
        unordered_map<string,int>mp;
        for(int i=0;i<n;i++)
        {
            string str= s.substr(i,10);
            if(mp[str]>0)
            {
                st.insert(str);
            }
            mp[str]++;
        }
        vector<string>ans;
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};