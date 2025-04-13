class Solution {
public:
    //METHOD-3
    //OPTIMIZED APPROACH..
    //TC= O(N^3)
    //SC= O(1)
    vector<vector<int>> fourSum(vector<int>& nums, int tar) 
    {
        int n= nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            for(int j=i+1;j<n;j++)
            {
                if(j>i+1 && nums[j]==nums[j-1])
                {
                    continue;
                }
                int l=j+1;
                int r=n-1;
                while(l<r)
                {
                    long long sum= nums[i];
                    sum+= nums[j];
                    sum+= nums[l];
                    sum+= nums[r];
                    if(sum==tar)
                    {
                        vector<int>temp= {nums[i],nums[j],nums[l],nums[r]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                        l++;
                        r--;
                        while(l<r && nums[l]==nums[l-1])
                        {
                            l++;
                        }
                        while(l<r && nums[r]==nums[r+1])
                        {
                            r--;
                        }
                    }
                    else if(sum<tar)
                    {
                        l++;
                    }
                    else
                    {
                        r--;
                    }
                }   
            }
        }
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    //TC= O(N^4 * LOG(unique quadruple))
    //SC= O(unique quadruple)

    vector<vector<int>> fourSum(vector<int>& nums, int tar) 
    {
        int n= nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    for(int l=k+1;l<n;l++)
                    {
                        int sum= nums[i]+nums[j]+nums[k]+nums[l];
                        if(sum==tar)
                        {
                            vector<int>temp= {nums[i],nums[j],nums[k],nums[l]};
                            sort(temp.begin(),temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }

    //METHOD-2
    //BETTER APPROACH..
    //TC= O(N^3 * LOG(unique quadruple))
    //SC= O(unique quadruple)
    vector<vector<int>> fourSum(vector<int>& nums, int tar) 
    {
        int n= nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                unordered_map<int,int>mp;
                for(int k=j+1;k<n;k++)
                {
                    int remain= tar-(nums[i]+nums[j]+nums[k]);
                    if(mp.find(remain)!=mp.end())
                    {
                        vector<int>temp= {nums[i],nums[j],nums[k],remain};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                    mp[nums[k]]=1;
                }
            }
        }
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
*/