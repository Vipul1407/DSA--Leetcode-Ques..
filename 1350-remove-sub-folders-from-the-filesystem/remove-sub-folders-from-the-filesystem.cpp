class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        vector<string>ans;
        unordered_set<string>uset(folder.begin(),folder.end());
        for(auto str:folder)
        {
            bool include=true;
            int n=str.size();
            int i=n-1;
            while(i>=0)
            {
                while(i>=0 && str[i]!='/')
                {
                    i--;
                }
                string sub= str.substr(0,i);
                //agar set me mila to ans me vo string ko include ni krenge..
                if(uset.find(sub)!=uset.end())
                {
                    include=false;
                    break;
                }
                //set me ni mila..
                else
                {
                    i--;
                }
            }
            if(include)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};