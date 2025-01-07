class Solution {
public:
    vector<string> stringMatching(vector<string>& words) 
    {
        int n= words.size();
        vector<string>ans;
        unordered_set<string>st;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j)
                {
                    continue;
                }
                if(words[i].find(words[j])!=string::npos)
                {
                    st.insert(words[j]);
                }
            }
        }
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};