class Solution {
public:
    //METHOD-1
    //BRUTE FORCE..
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            bool flag= false;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    ans.push_back(nums[j]);
                    flag= true;
                    break;
                }
            }
            if(!flag)
            {
                for(int j=0;j<i;j++)
                {
                    if(nums[j]>nums[i])
                    {
                        ans.push_back(nums[j]);
                        flag= true;
                        break;
                    }
                }
            }
            if(!flag)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
};