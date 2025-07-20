class Solution {
public:
    //METHOD-1
    //using unordered set..
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        vector<string>ans;
        unordered_set<string>st(folder.begin(),folder.end());
        for(auto &s:folder)
        {
            string str= s;
            bool flag= false;
            int i= str.size()-1;
            for(i;i>=0;i--)
            {
                if(str[i]=='/')
                {
                    string tofind= str.substr(0,i);
                    if(st.find(tofind)!=st.end())
                    {
                        flag= true;
                        break;
                    }
                }
            }
            if(!flag)
            {
                ans.push_back(s);
            }
        }
        return ans;
    }
};