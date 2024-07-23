class Solution {
public:
    static bool cmp(const pair<int,int>&a, const pair<int,int>&b)
    {
        if(a.second!=b.second)
        {
            //sort in ascending order based on count if freq not equal
            return a.second<b.second;
        }
        else
        {
            //sort in descending order
            return a.first>b.first;
        }
    }
    vector<int> frequencySort(vector<int>& nums) 
    {
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        vector<pair<int,int>>vec;//element, count
        for(auto i:mp)
        {
            vec.push_back({i.first,i.second});
        }
        sort(vec.begin(),vec.end(),cmp);
        vector<int>ans;
        for(auto i:vec)
        {
            while(i.second)
            {
                ans.push_back(i.first);
                i.second--;
            }
        }
        return ans;
    }
};