class Solution {
public:
    //METHOD-2
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int n= nums.size();
        vector<int>ans(n,pivot);

        int k=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            {
                ans[k++]=nums[i];
            }
        }

        k=n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(nums[i]>pivot)
            {
                ans[k--]=nums[i];
            }
        }

        return ans;
    }
};
/*
    //METHOD-1
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int cnt=0;
        int n= nums.size();
        vector<int>ans;

        for(int i=0;i<n;i++)
        {
            if(nums[i]<pivot)
            {
                ans.push_back(nums[i]);
            }
            else if(nums[i]==pivot)
            {
                cnt++;
            }
        }

         while(cnt--) 
        {
            ans.push_back(pivot);
        }

        for(int i=0;i<n;i++)
        {
            if(nums[i]>pivot)
            {
                ans.push_back(nums[i]);
            }
        }

        return ans;
    }
*/