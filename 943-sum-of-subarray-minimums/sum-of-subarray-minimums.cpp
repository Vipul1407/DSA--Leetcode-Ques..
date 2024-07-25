class Solution {
public:
    #define MOD 1000000007
    vector<int>nextsmall(vector<int>& arr)
    {
        int n= arr.size();
        vector<int>nse(n,0);
        stack<int>st;
        for(int i=n-1;i>=0;i--)
        {
            while(!st.empty() && arr[st.top()]>=arr[i])
            {
                st.pop();
            }
            nse[i]= st.empty()? n:st.top();//if stack empty then assign to n
            st.push(i);//add indexx
        }
        return nse;
    }
    vector<int>prevsmall(vector<int>& arr)
    {
        int n= arr.size();
        vector<int>pse(n,0);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(!st.empty() && arr[st.top()]>arr[i])//only pop in case of > not =
            {
                st.pop();
            }
            pse[i]= st.empty()? -1:st.top();
            st.push(i);//pushing index
        }
        return pse;
    }
    int sumSubarrayMins(vector<int>& arr) 
    {
        int n= arr.size();
        vector<int>nse= nextsmall(arr);
        vector<int>pse= prevsmall(arr);
        int total=0;
        for(int i=0;i<n;i++)
        {
            int left= i-pse[i];
            int right= nse[i]-i;
            total= (total+ left*right*1LL*arr[i])%MOD;//here arr[i] is contribution..
        }
        return total;
    }
};