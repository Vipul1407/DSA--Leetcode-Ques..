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
        deque<int>dq;//we need to check only end of arr
        int maxbeauty=0;
        for(auto i:arr)
        {
            while(dq.size() && dq.front()<i.first)
            {
                dq.pop_front();
            }
            dq.push_back(i.second);
            maxbeauty= max(maxbeauty, (int)dq.size());
        }
        return maxbeauty;
    }
};