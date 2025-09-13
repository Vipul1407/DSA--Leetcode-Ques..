class Solution {
public:
    //OPTIMIZED..
    //TC= O(N)
    //SC= O(1)
    int majorityElement(vector<int>& nums) 
    {
        int n= nums.size();
        int ele=-1;
        int cnt=0;
        for(auto i:nums)
        {
            if(cnt==0)
            {
                ele= i;
                cnt=1;
            }
            else if(ele==i)
            {
                cnt++;
            }
            else
            {
                cnt--;
            }
        }
        //must check again..
        cnt=0;
        for(auto i:nums)
        {
            if(i==ele)
            {
                cnt++;
            }
        }
        if(cnt> (n/2))
        {
            return ele;
        }
        return -1;
    }
};