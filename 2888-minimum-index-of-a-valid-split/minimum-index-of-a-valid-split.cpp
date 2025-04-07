class Solution {
public:
    //METHOD-1
    //USING UNORDERED MAP..
    int minimumIndex(vector<int>& nums) 
    {
        int n= nums.size();
        unordered_map<int,int>leftmp;
        unordered_map<int,int>rightmp;
        for(auto i:nums)
        {
            rightmp[i]++;
        }
        for(int i=0;i<n;i++)
        {
            leftmp[nums[i]]++;
            rightmp[nums[i]]--;
            int n1= i+1;
            int n2= n-1-i;
            if(leftmp[nums[i]]>n1/2 && rightmp[nums[i]]>n2/2)
            {
                return i;
            }
        }
        return -1;
    }
};