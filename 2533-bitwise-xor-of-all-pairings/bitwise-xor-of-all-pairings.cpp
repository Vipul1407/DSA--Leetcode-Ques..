class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        int n= nums1.size();
        int m= nums2.size();
        int ans=0;
        if(n%2==0 && m%2==0)
        {
            return 0;
        }    
        else if(n%2==0)
        {
            for(int i=0;i<n;i++)
            {
                ans^= nums1[i];
            }
        }
        else if(m%2==0)
        {
            for(int i=0;i<m;i++)
            {
                ans^= nums2[i];
            }
        }
        else
        {
            for(int i=0;i<n;i++)
            {
                ans^= nums1[i];
            }
            for(int i=0;i<m;i++)
            {
                ans^= nums2[i];
            }
        }
        return ans;
    }
};
/*
//METHOD-1
    //BRUTE FORCE..
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        vector<int>vec;
        int n=nums1.size();
        int m= nums2.size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                vec.push_back(nums1[i]^nums2[j]);
            }
        }
        int ans=0;
        for(int i=0;i<vec.size();i++)
        {
            ans^= vec[i];
        }
        return ans;
    }
*/