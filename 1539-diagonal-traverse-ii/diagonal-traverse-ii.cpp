class Solution {
public:
    //METHOD-1
    //USING Map Approach..
    //TC= O(M*N*LOG(M+N))
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        vector<int>ans;
        map<int,vector<int>>mp;
        for(int i=0;i<nums.size();i++)
        {
            for(int j=0;j<nums[i].size();j++)
            {
                mp[i+j].push_back(nums[i][j]);
            }
        }
        for(auto &i:mp)
        {
            vector<int>vec= i.second;
            reverse(begin(vec),end(vec));
    
            for(auto &j:vec)
            {
                ans.push_back(j);
            }
        }
        return ans;
    }
};