class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        int n= nums.size();
        int idx=-1;
        //when we get a dip in mountain then we have that in our idx..
        for(int i=n-2;i>=0;i--)
        {
            if(nums[i]<nums[i+1])
            {
                idx=i;
                break;
            }
        }
        //we have full array in decreasing order then it means it is the last permuatation and hence we will go to its 1st permutation
        if(idx==-1)
        {
            reverse(nums.begin(),nums.end());
        }
        else
        {
            for(int i=n-1;i>idx;i--)
            {
                //swap the nums[idx] with the just greater element..
                if(nums[i]>nums[idx])
                {
                    swap(nums[i],nums[idx]);
                    break;
                }
            }
            //reverse the nums for idx+1 to last..
            reverse(nums.begin()+idx+1,nums.end());
        }
    }
};
/*
// METHOD-1
// INBUILT STL
void nextPermutation(vector<int> &nums)
{
    next_permutation(nums.begin(), nums.end());
}
*/