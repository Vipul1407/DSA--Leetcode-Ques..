class Solution {
public:
    //METHOD-1
    //BRUTE FORCE..
    bool check(vector<int>& nums) 
    {
        int n= nums.size();
        for(int r=0;r<n;r++)
        {
            vector<int>vec;
            for(int i=r;i<n;i++)
            {
                vec.push_back(nums[i]);
            }
            for(int i=0;i<r;i++)
            {
                vec.push_back(nums[i]);
            }
            bool sorted= true;
            //check is it sorted also..
            for(int i=0;i<n-1;i++)
            {
                if(vec[i]>vec[i+1])
                {
                    sorted= false;
                    break;
                }
            }
            if(sorted)
            {
                return true;
            }
        }
        return false;
    }
};