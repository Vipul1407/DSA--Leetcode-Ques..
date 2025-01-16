class Solution {
public:
    //USING UNORDERED_MAP 
    //TC=O(M+N) SC=O(max(M,N))
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) 
    {
        unordered_map<long long,long long>mp;
        int n= nums1.size();
        int m= nums2.size();
        for(auto i:nums1)
        {
            //its effect will be other size times..
            mp[i]+=m;
        }
        for(auto i:nums2)
        {
            mp[i]+=n;//efect will be other size times..
        }
        int ans=0;
        for(auto i:mp)
        {
            if(i.second%2!=0)
            {
                ans^=i.first;
            }
        }
        return ans;
    }
};