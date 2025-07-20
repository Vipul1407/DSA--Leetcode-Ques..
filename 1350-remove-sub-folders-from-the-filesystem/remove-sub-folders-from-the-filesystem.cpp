class Solution {
public:
    //METHOD-2
    //using Sorting..
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        vector<string>ans;
        sort(folder.begin(),folder.end());
        ans.push_back(folder[0]);
        int n= folder.size();

        for(int i=1;i<n;i++)
        {
            string curr= folder[i];
            string prev= ans.back();
            prev+="/";
            //prev ni mila curr me jo index=0 se start ho..
            if(curr.find(prev)!=0)
            {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};
/*
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
*/