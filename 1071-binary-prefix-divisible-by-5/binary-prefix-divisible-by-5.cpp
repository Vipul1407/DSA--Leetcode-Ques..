class Solution {
public:
    //METHOD-1
    vector<bool> prefixesDivBy5(vector<int>& nums) 
    {
        int n= nums.size();
        vector<bool>ans;
        int pref=0;
        for(auto i:nums)
        {
            pref= (((pref*2)%5)+i%5)%5;
            if(pref%5==0)
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};