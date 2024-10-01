class Solution {
public:
    bool canArrange(vector<int>& arr, int k) 
    {
        int n= arr.size();
        vector<int>mp(k,0);
        for(auto e:arr)
        {
            int r= ((e%k)+k)%k;//number can be negative..
            mp[r]++;
        }
        if(mp[0]%2==1)
        {
            return false;
        }
        for(int i=1;i<=k/2;i++)
        {
            if(mp[i]!=mp[k-i])
            {
                return false;
            }
        }
        return true;
    }
};