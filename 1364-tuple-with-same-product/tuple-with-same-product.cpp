class Solution {
public:
    // METHOD-4
    // MOST OPTIMIZED.. 
    //TC= O(N^2)    
    int tupleSameProduct(vector<int>& nums) 
    {
        int n= nums.size();
        int tuples=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                mp[nums[i]*nums[j]]++;
            }
        }    
        for(auto i:mp)
        {
            int freq= i.second;
            tuples+= freq*(freq-1)/2;
        }
        return tuples*8;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
// TC= O(N^4)
int tupleSameProduct(vector<int> &nums)
{
    int n = nums.size();
    int tuples = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            // starting form 0 not from j+1
            for (int k = 0; k < n; k++)
            {
                for (int l = k + 1; l < n; l++)
                {
                    if (i != k && i != l && j != k && j != l)
                    {
                        if (nums[i] * nums[j] == nums[k] * nums[l])
                        {
                            tuples++;
                        }
                    }
                }
            }
        }
    }
    // each tuple is giving 8 ans but we have write for loop in such way that we always got 2 tuples for 1 tuple..
    return tuples * 4;
}

// METHOD-2
//  BETTER APPROACH
// TC= O(N^2 + NLOGN)
int tupleSameProduct(vector<int> &nums)
{
    int n = nums.size();
    int tuples = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            for (int k = i + 1; k < j; k++)
            {
                for (int l = j - 1; l > k; l--)
                {
                    if (nums[i] * nums[j] == nums[k] * nums[l])
                    {
                        tuples++;
                    }
                }
            }
        }
    }
    return tuples * 8;
}

// METHOD-3
// OPTIMIZED
// TC= O(N^3)
int tupleSameProduct(vector<int> &nums)
{
    int n = nums.size();
    int tuples = 0;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > i; j--)
        {
            int prod = nums[i] * nums[j];
            unordered_set<int> st;
            for (int k = i + 1; k < j; k++)
            {
                if (prod % nums[k] != 0)
                {
                    continue;
                }
                if (st.count(prod / nums[k]))
                {
                    tuples++;
                }
                st.insert(nums[k]);
            }
        }
    }
    return tuples * 8;
}
*/