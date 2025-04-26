class Solution {
public:
    //SAME AS SUBARRAY SUM DIVISBLE BY K..
    // find cnt in mp of (s2-s1+m)%m= k;
    //       s2%m -s1%m +m= k;
    //       (r1 -r2 +m)%m= k;
    //       r2= (r1-k+m)%m;
    long long countInterestingSubarrays(vector<int>& nums, int mod, int k) 
    {
        unordered_map<int,long long>mp;
        mp[0]=1;
        long long prefix=0;
        long long ans=0;
        for(auto i:nums)
        {
            prefix+= (i%mod==k);
            long long r1= prefix%mod;
            long long tar= (r1-k+mod)%mod;
            ans+= mp[tar];
            mp[r1]++;
        }
        return ans;
    }
};