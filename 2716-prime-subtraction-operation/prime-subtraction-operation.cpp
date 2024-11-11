class Solution {
public:
    bool primeSubOperation(vector<int>& nums) 
    {
        vector<int>sieve(1001,1);
        //0 and 1 is not prime numbers.. 
        //as 0 is neither prime nor composite and 
        // as 1 contains only 1 divisor but for a prime number it must contain 2 divisors 1 and itself..
        sieve[0]=0;
        sieve[1]=0;
        for(int i=2;i<=1000;i++)
        {
            for(int j=i*i;j<=1000;j+=i)
            {
                sieve[j]=0; 
            }
        }
        int n=nums.size();
        for(int j=n-2;j>=0;j--)
        {
            if(nums[j]<nums[j+1])
            {
                continue;
            }
            //here nums[i]>nums[i+1], we want to decrease it..
            for(int idx=2;idx<nums[j];idx++)
            {
                //if its prime..
                if(sieve[idx]==1)
                {
                    if(nums[j]-idx<nums[j+1])
                    {
                        nums[j]-=idx;//updating value
                        break;
                    }
                }
            }
            //becoz we need strictly sorted array
            if(nums[j]>=nums[j+1])
            {
                return false;
            }
        }
        return true;
    }
};