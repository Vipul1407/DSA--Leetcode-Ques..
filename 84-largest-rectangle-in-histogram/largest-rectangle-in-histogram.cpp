class Solution {
public:
    //METHOD-3
    //WITHOUT USING STACK + 3 PASS..
    int largestRectangleArea(vector<int>& heights) 
    {
        int n= heights.size();

        //prev smaller..
        vector<int>pse(n,-1);
        pse[0]=-1;
        for(int i=1;i<n;i++)
        {
            int prev= i-1;
            while(prev>=0 && heights[prev]>=heights[i])
            {
                prev= pse[prev];
            }
            pse[i]= prev;
        }

        //next smaller..
        vector<int>nse(n);
        nse[n-1]= n;
        for(int i=n-2;i>=0;i--)
        {
            int next= i+1;
            while(next<n && heights[next]>=heights[i])
            {
                next= nse[next];
            }
            nse[i]= next;
        }

        //finding ans....
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans= max(ans, heights[i]* (nse[i]-pse[i]-1));
        }
        return ans;
    }
};
/*
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

    //METHOD-2
    //2 PASS ONLY + STACK..
    int largestRectangleArea(vector<int>& heights) 
    {
        int n= heights.size();

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

        //prev smaller + finding ans....
        vector<int>pse(n,-1);
        stack<int>st1;
        st1.push(-1);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            while(st1.top()!=-1 && heights[st1.top()]>=heights[i])
            {
                st1.pop();
            }
            pse[i]= st1.top();
            st1.push(i);
            ans= max(ans, heights[i]* (nse[i]-pse[i]-1));
        }
        return ans;
    }
*/