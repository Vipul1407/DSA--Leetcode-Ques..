class Solution {
public:
    //METHOD-1
    //Using Priority queue (MAX HEAP..)
    //TC= O(NLOGN)..
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        //max heap.. storing freq,element
        priority_queue<pair<int,int>>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
        }
        while(pq.size() && k--)
        {
            auto ele= pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};