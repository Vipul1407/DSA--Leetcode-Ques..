class Solution {
public:
    int rec(int n,int k)
    {
        if(n==1)
        {
            return 0;
        }
        return (rec(n-1,k)+k)%n;
    }
    int findTheWinner(int n, int k) 
    {
        //becoz we need 1based indexing
        return rec(n,k)+1;
    }
};