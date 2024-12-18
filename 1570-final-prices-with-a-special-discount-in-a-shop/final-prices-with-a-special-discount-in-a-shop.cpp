class Solution {
public:
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
};