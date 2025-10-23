class Solution {
public:
    //METHOD-1
    //Make the correct position negative..
    int firstMissingPositive(vector<int>& nums) 
    {
        int n= nums.size();
        bool one= false;
        for(int i=0;i<n;i++)
        {
            //number should be in [1,..n] range only
            if(nums[i]<=0 || nums[i]>n)
            {
                nums[i]=1;//make it 1..
            }
            else if(nums[i]==1)
            {
                one= true;
            }
        }
        //1 is not present in array
        if(one==false)
        {
            return 1;
        }
        for(int i=0;i<n;i++)
        {
            int idx= abs(nums[i]);
            if(nums[idx-1]<0)
            {
                continue;
            }
            //mkaing it negative..
            nums[idx-1]*=-1;
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                return i+1;
            }
        }
        return n+1;
    }
};