class Solution {
public:
    //METHOD-2
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        int n= nums.size();
        int i=0;
        int j=n-1;
        vector<int>ans(n,pivot);

        for(int k=0;k<n;k++)
        {
            if(nums[k]<pivot)
            {
                ans[i++]= nums[k];
            }
        }   
        for(int k=n-1;k>=0;k--)
        {
            if(nums[k]>pivot)
            {
                ans[j--]= nums[k];
            }
        }
        return ans;
    }
};
/*
    //METHOD-1
    vector<int> pivotArray(vector<int>& nums, int pivot) 
    {
        vector<int>ans;
        int cnt=0;
        for(auto i:nums)
        {
            if(i<pivot)
            {
                ans.push_back(i);
            }
            else if(i==pivot)
            {
                cnt++;
            }
        }
        while(cnt--)
        {
            ans.push_back(pivot);
        }
        for(auto i:nums)
        {
            if(i>pivot)
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
*/