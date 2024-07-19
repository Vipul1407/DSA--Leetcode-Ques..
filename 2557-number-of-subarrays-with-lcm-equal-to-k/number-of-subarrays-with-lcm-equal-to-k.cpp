class Solution {
public:
    int gcd(int a, int b)
    {
        if(b==0)
        {
            return a;
        }
        return gcd(b,a%b);
    }
    int lcm(int a, int b)
    {
        //LCM=(a*b/gcd)
        return (a/gcd(a,b))*b;
    }
    int subarrayLCM(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            int curr =nums[i];//must be initialized with curr element but in gcd we do with 0
            for(int j=i;j<n;j++)
            {
                curr= lcm(curr, nums[j]);
                if(curr>k)
                {
                    break;
                }
                if(curr==k)
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};