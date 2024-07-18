class Solution 
{
public:
    //this will cnt that how many no. are less than or  equal to k
    int less_than_k(int ele, int m, int n)
    {
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            cnt+= min(ele/i, n);
        }
        return cnt;
    }
    int findKthNumber(int m, int n, int k) 
    {
        int l=1;
        int r=m*n;
        while(l<=r)
        {
            int mid= (l+r)/2;
            //will not check for equal as numbers can be repeatitive..
            if(less_than_k(mid,m,n)<k)
            {
                l= mid+1;
            }
            else
            {
                r= mid-1;
            }
        }
        return l;
    }
};