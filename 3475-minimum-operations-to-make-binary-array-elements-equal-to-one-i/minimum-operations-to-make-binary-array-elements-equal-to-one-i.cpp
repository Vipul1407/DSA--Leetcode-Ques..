class Solution {
public:
    int minOperations(vector<int>& nums) 
    {
        int n= nums.size();
        int cnt=0;
        for(int i=0;i<=n-3;i++)
        {
            if(nums[i]==0)
            {
                cnt++;
                //xor with 1 to get flipped number..
                nums[i]= nums[i]^1;
                nums[i+1]= nums[i+1]^1;
                nums[i+2]= nums[i+2]^1;
            }
        }
        return (nums[n-1]==1 && nums[n-2]==1)? cnt:-1;
    }
};