class Solution {
public:
    int bestClosingTime(string customers) 
    {
        int n= customers.size();

        //curr se phle kitne N the..
        vector<int>prefixNo(n+1,0);
        for(int i=1;i<=n;i++)
        {
            prefixNo[i]= prefixNo[i-1]+ ((customers[i-1]=='N') ? 1:0);
        }

        //curr included and uske baad kitne Y the..
        vector<int>suffixyes(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            suffixyes[i]= suffixyes[i+1]+ ((customers[i]=='Y') ? 1:0);
        }
        int ans=0;
        int mini= INT_MAX;
        for(int i=0;i<=n;i++)
        {
            if(suffixyes[i]+prefixNo[i] <mini)
            {
                mini= suffixyes[i]+prefixNo[i];
                ans= i;
            }
        }
        return ans;
    }
};