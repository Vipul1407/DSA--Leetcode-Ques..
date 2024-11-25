class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) 
    {
        int n= code.size();
        vector<int>ans(n,0);
        if(k==0)
        {
            return ans;
        }
        int i=-1,j=-1;
        //we are taking i at left and j at right ..(independent of k)
        if(k>0)
        {
            //i start at 1 and j at k
            i=1;
            j=k;
        }
        else
        {
            //i start at -k (here k already negative) and j at -1 
            //adding n in both to avoid out of bound index..
            i=n+k;
            j=n-1;
        }
        int sum=0;
        for(int q=i;q<=j;q++)
        {
            sum+= code[q];
        }
        for(int k=0;k<n;k++)
        {
            ans[k]= sum;
            sum-= code[i%n];//element at index=i ko minus kr..
            sum+= code[(j+1)%n];//element at index=j+1 ko add kr..
            i++;
            j++;
        }
        return ans;
    }
};