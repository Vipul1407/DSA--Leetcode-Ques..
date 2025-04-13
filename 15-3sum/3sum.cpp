class Solution {
public:
    //METHOD-3
    //OPTIMIZED APPROACH..
    //HASHING..
    //TC= O(N^2+ NLOGN)
    //SC=O(1)
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
            {
                continue;
            }
            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                int sum= nums[l]+nums[r]+nums[i];
                if(sum==0)
                {
                    vector<int>temp= {nums[i],nums[l],nums[r]};
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
                else if(sum<0)
                {
                    l++;
                }
                else
                {
                    r--;
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
    //TC= O(N^3)+ O(LOG(no. of  unique triplets))
    //SC=O(LOG(no. of  unique triplets))

    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n= nums.size();
        set<vector<int>>st;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(nums[i]+nums[j]+nums[k]==0)
                    {
                        vector<int>vec={nums[i],nums[j],nums[k]};
                        sort(vec.begin(),vec.end());
                        st.insert(vec);
                    }
                }
            }
        }
        vector<vector<int>>ans;
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }

    //METHOD-2
    //BETTER APPROACH..
    //HASHING..
    //TC= O(N^2*LOGM)
    //SC=O(N)+O(unique triplets)
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        int n= nums.size();
        vector<vector<int>>ans;
        set<vector<int>>st;
        for(int i=0;i<n;i++)
        {
            unordered_map<int,int>mp;
            for(int j=i+1;j<n;j++)
            {
                int tar= -(nums[i]+nums[j]);
                if(mp.find(tar)!=mp.end())
                {
                    vector<int>vec= {nums[i],nums[j],tar};
                    sort(vec.begin(),vec.end());
                    st.insert(vec);
                }
                mp[nums[j]]=1;
            }
        }
        for(auto i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
*/