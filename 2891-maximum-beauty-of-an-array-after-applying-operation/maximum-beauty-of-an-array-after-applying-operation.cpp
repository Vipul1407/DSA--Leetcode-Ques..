class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) 
    {
        //(x-k,x+k), (y-k,y+k)
        //for overlapping--> y-k<=x+k --> (y<=x+2k)
        sort(nums.begin(),nums.end());
        int ans=0;
        int n= nums.size();
        int i=0,j=0;
        for(int i=0;i<n;i++)
        {
            int val= nums[i]+2*k;
            while(j<n && nums[j]<=val)
            {
                j++;
            }
            ans= max(ans,j-i);
        }
        return ans;
    }
};

/*
// METHOD-1----------------------------------------->
// USING DEQUEUE
// TC= O(NLOGN)
int maximumBeauty(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<pair<int, int>> arr;
    for (auto i : nums)
    {
        arr.push_back({i - k, i + k});
    }
    sort(arr.begin(), arr.end());
    int maxsize = 0;
    // find max overlapping interval
    // we will use deque...
    deque<pair<int, int>> dq;
    for (auto &inter : arr)
    {
        while (dq.size() && dq.front().second < inter.first)
        {
            dq.pop_front();
        }
        dq.push_back(inter);
        maxsize = max(maxsize, (int)dq.size());
    }
    return maxsize;
}

// WILL ALSO WORK WHEN TAKEN ONLY DEQUE<INT> INSTEAD OF DEQUE<PAIR<INT,INT>> AS WELL
int maximumBeauty(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<pair<int, int>> arr;
    for (auto i : nums)
    {
        arr.push_back({i - k, i + k});
    }
    sort(arr.begin(), arr.end());
    deque<int> dq; // we need to check only end of arr
    int maxbeauty = 0;
    for (auto i : arr)
    {
        while (dq.size() && dq.front() < i.first)
        {
            dq.pop_front();
        }
        dq.push_back(i.second);
        maxbeauty = max(maxbeauty, (int)dq.size());
    }
    return maxbeauty;
}

// CAN ALSO TAKE QUEUE...
int maximumBeauty(vector<int> &nums, int k)
{
    int n = nums.size();
    vector<pair<int, int>> arr;
    for (auto i : nums)
    {
        arr.push_back({i - k, i + k});
    }
    sort(arr.begin(), arr.end());
    queue<int> q; // we need to check only end of arr
    int maxbeauty = 0;
    for (auto i : arr)
    {
        while (q.size() && q.front() < i.first)
        {
            q.pop();
        }
        q.push(i.second);
        maxbeauty = max(maxbeauty, (int)q.size());
    }
    return maxbeauty;
}

// METHOD-2------------------------------------------->
// USING BINARY SEARCH..
int binarys(vector<int> &nums, int idx, int k)
{
    int val = nums[idx] + 2 * k;
    int l = idx;
    int r = nums.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= val)
        {
            l = mid + 1; // to get large stopping index
        }
        else
        {
            r = mid - 1; // to find valid index
        }
    }
    return r - idx + 1; // length of subsequence..
}
int maximumBeauty(vector<int> &nums, int k)
{
    //(x-k,x+k), (y-k,y+k)
    // for overlapping--> y-k<=x+k --> (y<=x+2k)
    sort(nums.begin(), nums.end());
    int ans = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, binarys(nums, i, k));
    }
    return ans;
}
*/