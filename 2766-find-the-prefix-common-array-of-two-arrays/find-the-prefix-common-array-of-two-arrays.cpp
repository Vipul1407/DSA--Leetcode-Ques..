class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n= A.size();
        vector<int>ans(n,0);
        vector<int>store(n+1,0);
        for(int i=0;i<n;i++)
        {
            store[B[i]]=1;
            int cnt=0;
            for(int j=0;j<=i;j++)
            {
                if(store[A[j]]==1)
                {
                    cnt++;
                }
            }
            ans[i]= cnt;
        }
        return ans;
    }
};