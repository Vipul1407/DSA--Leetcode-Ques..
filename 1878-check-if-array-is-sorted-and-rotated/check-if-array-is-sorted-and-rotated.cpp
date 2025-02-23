class Solution {
public:
    // METHOD-3
    // OPTIMIZED APPROACH
    //Must contain only 1 peak in it and must check for last and 1st element..
    bool check(vector<int>& nums) 
    {
        int n= nums.size();
        int peak=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            {
                peak++;
                if(peak>1)
                {
                    return false;
                }
            }
        }
        return peak<=1;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
bool check(vector<int> &nums)
{
    int n = nums.size();
    for (int r = 0; r < n; r++)
    {
        vector<int> vec;
        for (int i = r; i < n; i++)
        {
            vec.push_back(nums[i]);
        }
        for (int i = 0; i < r; i++)
        {
            vec.push_back(nums[i]);
        }
        // check is it sorted ..
        bool sorted = true;
        for (int i = 0; i < n - 1; i++)
        {
            if (vec[i] > vec[i + 1])
            {
                sorted = false;
                break;
            }
        }
        if (sorted)
        {
            return true;
        }
    }
    return false;
}

// METHOD-2
// BETTER APPROACH
// TC= O(N*N)
bool check(vector<int> &nums)
{
    int n = nums.size();
    bool flag = true;
    vector<int> vec = nums;
    sort(vec.begin(), vec.end());
    for (int r = 0; r < n; r++)
    {
        bool flag = true;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != vec[(i + r) % n])
            {
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            return true;
        }
    }
    return false;
}
*/