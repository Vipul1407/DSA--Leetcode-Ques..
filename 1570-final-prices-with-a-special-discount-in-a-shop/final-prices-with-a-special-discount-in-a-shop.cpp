class Solution {
public:
    //METHOD-1
    //BRUTE FORCE..
    vector<int> finalPrices(vector<int>& prices) 
    {
        int n=prices.size();
        vector<int>ans(n,-1);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(st.size() && st.top()>prices[i])
            {
                st.pop();
            }
            if(st.size())
            {
                ans[i]= prices[i]-st.top();
            }
            else
            {
                ans[i]= prices[i];
            }
            st.push(prices[i]);
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    vector<int> finalPrices(vector<int>& prices) 
    {
        vector<int>arr;
        int n= prices.size();
        for(int i=0;i<n;i++)
        {
            int j=i+1;
            while(j<n && prices[j]>prices[i])
            {
                j++;
            }
            if(j>=n)
            {
                arr.push_back(prices[i]);
            }
            else
            {
                arr.push_back(prices[i]-prices[j]);
            }  
        }
        return arr;
    }
*/