class Solution {
public:
    void merge(int lb, int mid, int ub, vector<int>&nums)
    {
        //merging both starting from lb and from mid+1
        vector<int>temp;
        int i=lb;
        int j=mid+1;
        while(i<=mid && j<=ub)
        {
            if(nums[i]<=nums[j])
            {
                temp.push_back(nums[i++]);
            }
            else if(nums[j]<nums[i])
            {
                temp.push_back(nums[j++]);
            }
        }
        while(i<=mid)
        {
            temp.push_back(nums[i++]);
        }
        while(j<=ub)
        {
            temp.push_back(nums[j++]);
        }
        for(int i=lb;i<=ub;i++)
        {
            nums[i]= temp[i-lb];
        }
    }
    void mergesort(int lb, int ub, vector<int>& nums)
    {
        int mid= (lb+ub)/2;
        if(lb<ub)
        {
            mergesort(lb,mid,nums);
            mergesort(mid+1,ub,nums);
            merge(lb,mid,ub,nums);
        }
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        int n= nums.size();
        mergesort(0, n-1, nums);
        return nums;
    }
};