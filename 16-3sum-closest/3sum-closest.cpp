class Solution {
public:
    int threeSumClosest(vector<int>& nums, int tar) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
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
                    if(abs(tar-sum)<diff)
                    {
                        diff= abs(tar-sum);
                        ans= sum;
                    }
                    j++;
                    while(j<k && nums[j]==nums[j-1])
                    {
                        j++;
                    }
                }
                else if(sum>tar)
                {
                    if(abs(tar-sum)<diff)
                    {
                        diff= abs(tar-sum);
                        ans= sum;
                    }
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
            }
        }
        return ans;
    }
};