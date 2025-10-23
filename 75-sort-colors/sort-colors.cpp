class Solution {
public:
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
};