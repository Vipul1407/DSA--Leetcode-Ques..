class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& quer) 
    {
        int n= nums.size();
        vector<int>pref(n,0);
    
        for(int i=1;i<n;i++)
        {
            if(nums[i]%2==0 && nums[i-1]%2==0)
            {
                pref[i]=pref[i-1]+1;
            }
            else if(nums[i]%2==1 && nums[i-1]%2==1)
            {
                pref[i]=pref[i-1]+1;
            }
            else
            {
                pref[i]=pref[i-1];
            }
        }
        vector<bool>res;
        for(auto i:quer)
        {
            if(pref[i[1]]-pref[i[0]]==0)
            {
                res.push_back(true);
            }
            else
            {
                res.push_back(false);
            }
        }
        return res;    
    }
};