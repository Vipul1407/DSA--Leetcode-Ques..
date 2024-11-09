class Solution {
public:
    long long minEnd(int n, int x) 
    {
        //to get the next value whose and value is same as x
        //so our 1st no. is x for 2nd
        //we will take x+1 and take OR of x and x+1
        //for 3rd no. we will take the above result and OR with x+2
        //and so on..

        n--;//as our 1st no. is x itself
        long long ans= x;
        while(n>0)
        {
            ans= (ans+1)|x;
            n--;
        }
        return ans;
    }
};