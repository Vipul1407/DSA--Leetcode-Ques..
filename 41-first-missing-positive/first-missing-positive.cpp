class Solution {
public:
    //METHOD-2
    //Swapping elements at their coorect position..
    int firstMissingPositive(vector<int>& nums) 
    {
        int n= nums.size();

        //numbers should be at their coorect position of i+1, [1..n]
        for(int i=0;i<n;i++)
        {
            while(nums[i]>=1 && nums[i]<n && nums[nums[i]-1]!=nums[i])
            {
                swap(nums[i],nums[nums[i]-1]);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return n+1;
    }
};
/*
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
*/