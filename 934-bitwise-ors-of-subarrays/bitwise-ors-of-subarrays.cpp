class Solution 
{
public:

    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int>st;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            st.insert(arr[i]);
            for(int j=i-1;j>=0;j--)
            {
                if((arr[i]|arr[j])==arr[j])
                {
                    break;
                }
                arr[j]|=arr[i];
                st.insert(arr[j]);
            }
        }
        return st.size();
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    //TC= O(N^2)
    int solve(int i, vector<int>& arr, int binary_or, unordered_set<int>&st)
    {
        if(i>=arr.size())
        {
            return 0;
        }
        binary_or|= arr[i];
        st.insert(binary_or);
        return solve(i+1,arr,binary_or,st);
    }
    int subarrayBitwiseORs(vector<int>& arr) 
    {
        unordered_set<int>st;
        int n= arr.size();
        for(int i=0;i<n;i++)
        {
            solve(i,arr,0,st);
        }
        return st.size();
    }
*/
