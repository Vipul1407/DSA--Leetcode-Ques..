class Solution {
public:
    //METHOD-1
    //BRUTE FORCE..
    //3 PASS + STACK..
    int largestRectangleArea(vector<int>& heights) 
    {
        int n= heights.size();

        //prev smaller..
        vector<int>pse(n,-1);
        stack<int>st1;
        st1.push(-1);
        for(int i=0;i<n;i++)
        {
            while(st1.top()!=-1 && heights[st1.top()]>=heights[i])
            {
                st1.pop();
            }
            pse[i]= st1.top();
            st1.push(i);
        }

        //next smaller..
        vector<int>nse(n,n);
        stack<int>st2;
        st2.push(n);
        for(int i=n-1;i>=0;i--)
        {
            while(st2.top()!=n && heights[st2.top()]>=heights[i])
            {
                st2.pop();
            }
            nse[i]= st2.top();
            st2.push(i);
        }

        //finding ans..
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans= max(ans, heights[i]* (nse[i]-pse[i]-1));
        }
        return ans;
    }
};