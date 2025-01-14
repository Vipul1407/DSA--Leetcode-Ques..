class Solution {
public:
    
    // METHOD-3
    //To take the advantage of the fact that the elements are in permutation hence must have cnt of 2 if present in both..
    // TC=O(N) SC=O(N)
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) 
    {
        int n= A.size();
        vector<int>ans(n,0);

        //to indicate presence of a element..
        vector<int>store(n+1,0);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            store[A[i]]++;
            if(store[A[i]]==2)
            {
                cnt++;
            }
            store[B[i]]++;
            if(store[B[i]]==2)
            {
                cnt++;
            }
            ans[i]= cnt;
        }
        return ans;
    }
};
/*
// METHOD-1
//  BRUTE FORCE
//  TC= O(N^3) SC=O(1)
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j <= i; j++)
        {
            int ele = A[j];
            for (int k = 0; k <= i; k++)
            {
                if (B[k] == ele)
                {
                    cnt++;
                }
            }
        }
        ans[i] = cnt;
    }
    return ans;
}

// METHOD-2
// Using Vector to store previous presence..
//  TC= O(N^2) SC=O(N)
vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B)
{
    int n = A.size();
    vector<int> ans(n, 0);
    vector<int> store(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        store[B[i]] = 1;
        int cnt = 0;
        for (int j = 0; j <= i; j++)
        {
            if (store[A[j]] == 1)
            {
                cnt++;
            }
        }
        ans[i] = cnt;
    }
    return ans;
}
*/