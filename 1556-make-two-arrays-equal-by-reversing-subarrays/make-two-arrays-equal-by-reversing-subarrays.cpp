class Solution {
public:
    bool canBeEqual(vector<int>& tar, vector<int>& arr) 
    {
        unordered_map<int,int>mp;
        int n= arr.size();
        for(int i=0;i<n;i++)
        {
            mp[tar[i]]++;
            mp[arr[i]]--;
        }
        for(auto i:mp)
        {
            if(i.second!=0)
            {
                return false;
            }
        }
        return true;
    }
};