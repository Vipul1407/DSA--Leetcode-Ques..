class Solution {
public:
    int maxBottlesDrunk(int n, int ex) 
    {
        int ans= n;
        while(n>=ex)
        {
            ans+= 1;
            n= n-ex+1;
            ex++;
        }    
        return ans;
    }
};