class Solution {
public:
    int count(long long curr,long long next,int n)
    {
        int cnt=0;
        while(curr<=n)
        {
            cnt+= (next-curr);
            curr*=10;
            next*=10;
            next= min(next, (long long)n+1);
        }
        return cnt;
    }
    int findKthNumber(int n, int k) 
    {
        int curr=1;
        k--;
        while(k>0)
        {
            int cnt= count(curr,curr+1,n);
            //go to next prefix tree
            if(cnt<=k)
            {
                curr++;
                k-=cnt;
            }
            else
            {
                curr*=10;
                k--;
            }
        }
        return curr;
    }
};