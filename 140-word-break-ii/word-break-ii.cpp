class Solution {
public:
    void solve(int i,string &curr,string &s,unordered_set<string>&st,vector<string>&ans)
    {
        if(i>=s.size())
        {
            ans.push_back(curr);
            return;
        }
        for(int len=1;i+len<=s.size();len++)
        {
            string temp= s.substr(i,len);
            if(st.find(temp)!=st.end())
            {
                string next= curr.empty()? temp: curr+" "+temp;
                solve(i+len,next,s,st,ans);
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        unordered_set<string>st(wordDict.begin(),wordDict.end());
        string curr;
        vector<string>ans;
        solve(0,curr,s,st,ans);
        return ans;
    }
};