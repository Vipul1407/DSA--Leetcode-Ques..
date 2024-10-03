class Solution {
public:
    int subarraysDivByK(vector<int>& arr, int p) 
    {
        int n= arr.size();
        int ans=0;
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=1;
        for(auto i:arr)
        {
            //becoz numbers can be negative..
            //to avoid negative remainder we use this...
            sum= (sum+(i%p)+p)%p;
            int remain= sum%p;
            ans+= mp[remain];
            mp[sum]++;
        }
        return ans;
    }
};