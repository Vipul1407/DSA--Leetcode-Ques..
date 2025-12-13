class Solution {
public:
    //METHOD-2
    //TC= O(N*(K+26))
    string func(string &s)
    {
        string str="";
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            while(vec[i]--)
            {
                str+= (i+'a');
            }
        }
        return str;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n= strs.size();
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto s:strs)
        {
            string key= func(s);
            mp[key].push_back(s);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //TC= O(N* K*(LOG K))
    vector<vector<string>> groupAnagrams(vector<string>& strs) 
    {
        int n= strs.size();
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(auto s:strs)
        {
            string key= s;
            sort(begin(key),end(key));
            mp[key].push_back(s);
        }
        for(auto it:mp)
        {
            ans.push_back(it.second);
        }
        return ans;
    }
*/