class Solution {
public:
    // METHOD-4
    // MORE READABLE AND SIMPLE OPTIMIZED APPROACH
    // TC=O(M+N) SC=O(1)
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int n= nums1.size();
        int m= nums2.size();
        int ans=0;

        //if odd size.. then it will impact other...
        if(n%2!=0)
        {
            for(int i=0;i<m;i++)
            {
                ans^= nums2[i];
            }
        }
        if(m%2!=0)
        {
            for(int i=0;i<n;i++)
            {
                ans^= nums1[i];
            }
        }
        return ans;
    }
};
/*
// METHOD-1
// BRUTE FORCE..
int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    vector<int> vec;
    int n = nums1.size();
    int m = nums2.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            vec.push_back(nums1[i] ^ nums2[j]);
        }
    }
    int ans = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        ans ^= vec[i];
    }
    return ans;
}

// METHOD-2
// BEATS 5%
// MIK APPROACH-1
// USING UNORDERED_MAP
// TC=O(M+N) SC=O(max(M,N))
int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    unordered_map<long long, long long> mp;
    int n = nums1.size();
    int m = nums2.size();
    for (auto i : nums1)
    {
        // its effect will be other size times..
        mp[i] += m;
    }
    for (auto i : nums2)
    {
        mp[i] += n; // efect will be other size times..
    }
    int ans = 0;
    for (auto i : mp)
    {
        if (i.second % 2 != 0)
        {
            ans ^= i.first;
        }
    }
    return ans;
}

// METHOD-3
// OPTIMIZED..
// BEATS 100%
// MY WAY.. TC=O(N+M) SC=O(1)
int xorAllNums(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int m = nums2.size();
    int ans = 0;
    // both have even size... all xor will cancel to 0
    if (n % 2 == 0 && m % 2 == 0)
    {
        return 0;
    }
    // if n is even and m is odd.. then only elments of nums1 will effect xor
    else if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            ans ^= nums1[i];
        }
    }
    // if m is even and n is odd.. then only elements of nums2 will effect xor
    else if (m % 2 == 0)
    {
        for (int i = 0; i < m; i++)
        {
            ans ^= nums2[i];
        }
    }
    // if both m and n is odd then both have effect on xor..
    else
    {
        for (int i = 0; i < n; i++)
        {
            ans ^= nums1[i];
        }
        for (int i = 0; i < m; i++)
        {
            ans ^= nums2[i];
        }
    }
    return ans;
}
*/