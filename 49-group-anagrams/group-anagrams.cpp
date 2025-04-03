class Solution {
public:

    //METHOD-2
    //WITHOUT USING SORTING
    //TC= O(N*(K+26)) where K is the length of largest word..
    vector<vector<string>> groupAnagrams(vector<string>& arr) 
    {
        int n= arr.size();
        unordered_map<string,vector<string>>mp;
        for(auto i:arr)
        {
            vector<int>cnt(26,0);
            for(auto j:i)
            {
                cnt[j-'a']++;
            }
            string temp="";
            for(int i=0;i<26;i++)
            {
                while(cnt[i]--)
                {
                    temp+= i+'a';
                }
            }
            mp[temp].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //USING SORTING
    //TC= O(N*KLOGK) where K is the length of largest word..
    vector<vector<string>> groupAnagrams(vector<string>& arr) 
    {
        int n= arr.size();
        unordered_map<string,vector<string>>mp;
        for(int i=0;i<n;i++)
        {
            auto str= arr[i];
            sort(str.begin(),str.end());
            mp[str].push_back(arr[i]);
        }
        vector<vector<string>>ans;
        for(auto i:mp)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
*/