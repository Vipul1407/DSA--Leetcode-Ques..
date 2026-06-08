class Solution {
public:
    //METHOD-1
    //2 Pass Sol
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
};