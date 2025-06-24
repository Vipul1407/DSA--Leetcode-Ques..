class Solution {
public:
    //METHOD-2
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) 
    {
        int n= nums.size();
        vector<int>ans;
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==key)
            {
                int left= max(0,i-k);
                int right= min(n-1,i+k);
                while(start<=right)
                {
                    if(start>=left)
                    {
                        ans.push_back(start);
                    }
                    start++;
                }
            }
        }
        return ans;
    }
};
/*
    // METHOD-1
vector<int> findKDistantIndices(vector<int> &nums, int key, int k)
{
    int n = nums.size();
    vector<int> vec, ans;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == key)
        {
            vec.push_back(i);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (auto j : vec)
        {
            if (abs(i - j) <= k)
            {
                ans.push_back(i);
                break;
            }
        }
    }
    return ans;
}
*/