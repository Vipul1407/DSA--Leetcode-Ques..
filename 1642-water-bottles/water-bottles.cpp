class Solution {
public:
    int numWaterBottles(int n, int ex) 
    {
        int ans=n;
        while(n/ex>0)
        {
            ans+= n/ex;
            n= n%ex+n/ex;
        }
        return ans;
    }
};