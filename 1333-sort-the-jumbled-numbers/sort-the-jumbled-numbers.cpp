class Solution {
public:
    static bool cmp(const pair<int,int>&a, const pair<int,int>&b)
    {
        return a.second<b.second;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) 
    {
        vector<int>ans;
        vector<pair<int,int>>vec;//original mapping given, converted string
        for(auto i:nums)
        {
            string str= to_string(i);
            string form="";
            for(char c:str)
            {
                form+= to_string(mapping[c-'0']);
            }
            vec.push_back({i,stoi(form)});
        }
        sort(vec.begin(),vec.end(),cmp);

        for(auto i:vec)
        {
            ans.push_back(i.first);
        }
        return ans;
    }
};