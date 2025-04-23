class Solution {
public:
    //METHOD-3
    //Using Priority queue (MIN HEAP..)
    //TC= O(NLOGK).. Somewhat better than others..
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto i:nums)
        {
            mp[i]++;
        }
        //min heap of size k only.. storing freq,element
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto i:mp)
        {
            pq.push({i.second,i.first});
            while(pq.size()>k)
            {
                pq.pop();
            }
        }
        while(pq.size())
        {
            auto ele= pq.top();
            pq.pop();
            ans.push_back(ele.second);
        }
        return ans;
    }
};
/*
    // IMPORTANT POINTS....
    // Sorting sort(vec.rbegin(), vec.rend()); will sort vec in descending order based on first element
    //  and 1st element are same then on basis of second elemtn but also in descending order...

    // Sorting sort(vec.begin(), vec.end()); will sort vec in ascending order based on first element
    //  and if 1st element are same then on basis of second elemtn but also in ascending order...

    // We cannot sort a unordered_map<int,int> or map<int,int>
    // mp<int,int> will only place element in index wise arrangent form i=0 to n but not in sorted form on basis of count..

// METHOD-1
// Using Sorting
// TC= O(NLOGN)..
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }
    // storing freq, element..
    vector<pair<int, int>> vec;
    for (auto i : mp)
    {
        vec.push_back({i.second, i.first});
    }
    sort(vec.rbegin(), vec.rend());
    int i = 0;
    while (k--)
    {
        // pushing element having most to least freq..
        ans.push_back(vec[i].second);
        i++;
    }
    return ans;
}

// METHOD-2
// Using Priority queue (MAX HEAP..)
// TC= O(NLOGN)..
vector<int> topKFrequent(vector<int> &nums, int k)
{
    vector<int> ans;
    unordered_map<int, int> mp;
    for (auto i : nums)
    {
        mp[i]++;
    }
    // max heap.. storing freq,element
    priority_queue<pair<int, int>> pq;
    for (auto i : mp)
    {
        pq.push({i.second, i.first});
    }
    while (pq.size() && k--)
    {
        auto ele = pq.top();
        pq.pop();
        ans.push_back(ele.second);
    }
    return ans;
}
*/