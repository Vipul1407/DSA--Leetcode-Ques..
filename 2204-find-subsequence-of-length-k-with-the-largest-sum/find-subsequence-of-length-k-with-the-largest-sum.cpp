class Solution {
public:
    //METHOD-1
    //Using Vector..
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({nums[i],i});
        }
        sort(vec.rbegin(),vec.rend());
        vector<pair<int,int>>arr;
        int size=0;
        for(auto i:vec)
        {
            arr.push_back({i.second,i.first});
            size++;
            if(size==k)
            {
                break;
            }
        }
        sort(arr.begin(),arr.end());
        vector<int>res;
        for(auto i:arr)
        {
            res.push_back(i.second);
        }
        return res;
    }
};