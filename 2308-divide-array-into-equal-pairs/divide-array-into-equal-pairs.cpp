class Solution {
public:
    bool divideArray(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>arr(501,0);
        int cnt=0;
        for(auto i:nums)
        {
            arr[i]++;
        }
        for(int i=0;i<=500;i++)
        {
            if(arr[i]==0)
            {
                continue;
            }
            if(arr[i]%2==0)
            {
                cnt+= arr[i]/2;
            }
        }
        return cnt==n/2;
    }
};