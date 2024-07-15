class Solution {
public:

    bool isprime(int n)
    {
        int cnt=0;
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                cnt++;
                if(n/i!=i)
                {
                    cnt++;
                }
                if(cnt>2)
                {
                    return false;
                }
            }
        }
        //becoz 1 is not a prime number
        return cnt==2;
    }
    int maximumPrimeDifference(vector<int>& nums) 
    {
        int prev=-1;
        int ans=INT_MIN;
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(isprime(nums[i]))
            {
                cnt++;
                if(prev==-1)
                {
                    prev=i;
                }
                else
                {
                    ans= max(ans, abs(i-prev));
                    prev=min(prev,i);
                }
            }
        }
        return cnt==1?0:ans;
    }
};