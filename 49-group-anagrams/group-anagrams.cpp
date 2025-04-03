class Solution {
public:
    //METHOD-1
    //USING SORTING
    //TC= O(K*NLOGN)
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
};