class Solution {
public:
    //METHOD-1
    //Using Min Heap..
    //TC= O(NLOGK + KLOGK)
    //SC= O(K)
    vector<int> maxSubsequence(vector<int>& nums, int k) 
    {
        int n= nums.size();
        //min heap..
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;

        for(int i=0;i<n;i++)
        {
            pq.push({nums[i],i});
            if(pq.size()>k)
            {
                pq.pop();
            }
        }

        vector<pair<int,int>>arr;
        while(pq.size())
        {
            arr.push_back({pq.top().second,pq.top().first});
            pq.pop();
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
/*
    //METHOD-1
    //Using Vector..
    //TC= O(NLOGN + KLOGK)
    //SC= O(N+K)
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
*/