class Solution {
public:
    //METHOD-2
    //2 Pointers..
    void sortColors(vector<int>& nums) 
    {
        int l=0,r=nums.size()-1;
        int mid=0;

        while(mid<=r)
        {
            if(nums[mid]==0)
            {
                swap(nums[l++],nums[mid++]);
            }
            else if(nums[mid]==1)
            {
                mid++;
            }  
            //do not increase mid here..  
            else
            {
                swap(nums[mid],nums[r--]);
            }    
        }
    }
};
/*
    //METHOD-1
    //Uisng extra space..
    void sortColors(vector<int>& nums) 
    {
        int zero=0,one=0,two=0;
        for(auto i:nums)
        {
            if(i==0)
            {
                zero++;
            }
            else if(i==1)
            {
                one++;
            }
            else
            {
                two++;
            }
        }
        int n= nums.size();
        for(int i=0;i<n;i++)
        {
            if(zero>0)
            {
                nums[i]=0;
                zero--;
            }
            else if(one>0)
            {
                nums[i]=1;
                one--;
            }    
            else
            {
                nums[i]=2;
            }    
        }
    }
*/