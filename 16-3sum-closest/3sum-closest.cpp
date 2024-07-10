class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());

        int sum= nums[0]+nums[1]+nums[2];
        if(n==3)
        {
            return sum;
        }
        //base cases to make code faster..
        //since nums in sorted means agar abhi starting me hi sum bda aagya to mtlb 
        //yhi closest h kyoki baad me to aur bda aaega
        if(sum>=tar)
        {
            return sum;
        }

        if(nums[n-1]+nums[n-2]+nums[n-3]<=tar)
        {
            return nums[n-1]+nums[n-2]+nums[n-3];
        }
        
        int diff =INT_MAX;
        int ans= tar;
        //i==>fix
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int j=i+1;
            int k=n-1;
            while(j<k)
            {
                int sum= nums[i]+nums[j]+nums[k];
                if(sum<tar)
                {
                    j++;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                }
                else if(sum>tar)
                {
                    k--;
                    while(j<k && nums[k]==nums[k+1])
                    {
                        k--;
                    }
                }
                else
                {
                    return tar;
                }
                if(abs(tar-sum)<diff)
                {
                    diff= abs(tar-sum);
                    ans= sum;
                }
            }
        }
        return ans;
    }
};