class Solution {
public:
    //METHOD-3 
    //BFS approach
    //Only chnage is that we are pushing into ans earlier....
    //TC= O(M*N) since we are inserting every element if not want to insert then O(M+N)
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) 
    {
        vector<int>ans;
        queue<pair<int,int>>q;
        q.push({0,0});
        
        while(q.size())
        {
            int size= q.size();
            while(size--)
            {
                int x= q.front().first;
                int y= q.front().second;
                ans.push_back(nums[x][y]);
                if(y==0 && x+1<nums.size())
                {
                    q.push({x+1,y});
                }
                if(y+1<nums[x].size())
                {
                    q.push({x,y+1});
                }
                q.pop();
            }
        }
        return ans;
    }
};
/*
    /METHOD-1
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

    //METHOD-2
    //USING Unordered_Map Approach..
    //TC= O(M*N)
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
        int dia=0;
        while(mp.find(dia)!=mp.end())
        {
            vector<int>vec= mp[dia];
            reverse(vec.begin(),vec.end());
            for(auto &j:vec)
            {
                ans.push_back(j);
            }
            dia++;
        }
        return ans;
    }
*/