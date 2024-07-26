class Solution {
public:
    vector<int>nextsmall(vector<int>& nums)
    {
        int n= nums.size();
        vector<int>nse(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]>=nums[i])
            {
                st.pop();
            }
            nse[i]= st.empty()? n: st.top();
            st.push(i);
        }
        return nse;
    }
    vector<int>prevsmall(vector<int>& nums)
    {
        int n= nums.size();
        vector<int>pse(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]>nums[i])
            {
                st.pop();
            }
            pse[i]= st.empty()? -1:st.top();
            st.push(i);
        }
        return pse;
    }
    
    vector<int>nextgreat(vector<int>& nums)
    {
        int n= nums.size();
        vector<int>nge(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && nums[st.top()]<=nums[i])
            {
                st.pop();
            }
            nge[i]= st.empty()? n: st.top();
            st.push(i);
        }
        return nge;
    }
    vector<int>prevgreat(vector<int>& nums)
    {
        int n= nums.size();
        vector<int>pge(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && nums[st.top()]<nums[i])
            {
                st.pop();
            }
            pge[i]= st.empty()? -1:st.top();
            st.push(i);
        }
        return pge;
    }
    
    long long subArrayRanges(vector<int>& nums) 
    {
        int n= nums.size();
        vector<int>nse= nextsmall(nums);
        vector<int>pse= prevsmall(nums);
        vector<int>nge= nextgreat(nums);
        vector<int>pge= prevgreat(nums);
        long long ans=0;

        for(int i=0;i<n;i++)
        {
            long long left= i- pse[i];
            long long right= nse[i]-i;
            ans-= left*right*nums[i];

            left= i-pge[i];
            right= nge[i]-i;
            ans+= left*right*nums[i];
        }
        return ans;
    }
};