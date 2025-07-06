class Solution {
public:
    //METHOD-3
    //OPTIMIZED..
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=2*n-1;i>=0;i--)
        {
            int ele= nums[i%n];
            while(st.size() && st.top()<=ele)
            {
                st.pop();
            }
            if(i<n)
            {
                if(!st.empty())
                {
                    ans[i]= st.top();
                }
            }
            st.push(ele);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            bool flag= false;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    ans.push_back(nums[j]);
                    flag= true;
                    break;
                }
            }
            if(!flag)
            {
                for(int j=0;j<i;j++)
                {
                    if(nums[j]>nums[i])
                    {
                        ans.push_back(nums[j]);
                        flag= true;
                        break;
                    }
                }
            }
            if(!flag)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }

    //METHOD-2
    //BETTER FORCE..
    vector<int> nextGreaterElements(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            bool flag= false;
            for(int j=i+1;j<i+n;j++)
            {
                if(nums[j%n]>nums[i])
                {
                    ans.push_back(nums[j%n]);
                    flag= true;
                    break;
                }
            }
            if(!flag)
            {
                ans.push_back(-1);
            }
        }
        return ans;
    }
*/