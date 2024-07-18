class Solution 
{
public:
    //this will cnt that how many no. are greater than or equal to k
    bool func(int ele, int m, int n, int k)
    {
        int cnt=0;
        for(int i=1;i<=m;i++)
        {
            cnt+= min(ele/i, n);
            if(cnt==0)
            {
                break;
            }
        }
        return cnt>=k;
    }
    int findKthNumber(int m, int n, int k) 
    {
        int l=1;
        int r=m*n;
        int ans=0;
        while(l<=r)
        {
            int mid= (l+r)/2;
            //will not check for ==k (equal) as numbers can be repeatitive..
            
            if(func(mid,m,n,k))
            {
                ans=mid;
                r= mid-1;
            }
            else
            {
                l= mid+1;
            }
        }
        return ans;
    }
};