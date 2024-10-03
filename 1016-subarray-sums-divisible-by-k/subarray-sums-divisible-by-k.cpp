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
            sum+=i;
            int remain= sum%p;
            //becoz numbers can be negative..
            //to avoid negative remainder we use this...
            if(remain<0)
            {
                remain= (remain%p)+p;
            }
            ans+= mp[remain];
            mp[remain]++;
        }
        return ans;
    }
};