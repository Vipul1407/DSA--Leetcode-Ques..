class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) 
    {
        int n= nums.size();
        int i=0,j=0;
        //we are taking sorted map to take care the min element can be find by mp.begin() and max element can be find by mp.rbegin()
        map<int,int>mp;
        long long ans=0;
        while(j<n)
        {
            mp[nums[j]]++;
            while(i<n && (mp.rbegin()->first-mp.begin()->first)>2)
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            ans+= j-i+1;
            j++;
        }
        return ans;
    }
};