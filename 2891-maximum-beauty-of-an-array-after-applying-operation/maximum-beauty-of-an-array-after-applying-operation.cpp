class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        int n= nums.size();
        vector<pair<int,int>>arr;
        for(auto i:nums)
        {
            arr.push_back({i-k,i+k});
        }
        sort(arr.begin(),arr.end());
        int maxsize=0;
        //find max overlapping interval
        //we will use deque...
        deque<pair<int,int>>dq;
        for(auto &inter: arr)
        {
            while(dq.size() && dq.front().second<inter.first)
            {
                dq.pop_front();
            }
            dq.push_back(inter);
            maxsize= max(maxsize, (int)dq.size());
        }
        return maxsize;
    }
};