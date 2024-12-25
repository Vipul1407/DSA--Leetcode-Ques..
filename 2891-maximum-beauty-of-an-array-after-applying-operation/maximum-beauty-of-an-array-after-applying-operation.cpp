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
        queue<int>q;//we need to check only end of arr
        int maxbeauty=0;
        for(auto i:arr)
        {
            while(q.size() && q.front()<i.first)
            {
                q.pop();
            }
            q.push(i.second);
            maxbeauty= max(maxbeauty, (int)q.size());
        }
        return maxbeauty;
    }
};