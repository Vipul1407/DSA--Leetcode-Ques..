class Solution {
    public:
    // METHOD-2
    // OPTIMIZED...
    int largestRectangleArea(vector<int> &heights)
    {
        int n = heights.size();
        vector<int> prevsmallidx(n, -1);
        stack<int> st;
        for (int i = 0; i < n; i++)
        {
            while (st.size() && heights[st.top()] >= heights[i])
            {
                st.pop();
            }
            if (!st.empty())
            {
                prevsmallidx[i] = st.top();
            }
            st.push(i); // placing idx only..
        }

        stack<int> st2;
        int ans = 0;
        int nextsmallidx = n;
        for (int i = n - 1; i >= 0; i--)
        {
            while (st2.size() && heights[st2.top()] >= heights[i])
            {
                st2.pop();
            }
            if (!st2.empty())
            {
                nextsmallidx = st2.top();
            }
            else
            {
                nextsmallidx = n;
            }
            st2.push(i); // placing idx only..
            ans = max(ans, heights[i] * (nextsmallidx - prevsmallidx[i] - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int ans=0;
        int m= matrix.size();
        int n= matrix[0].size();
        //compute prefix column sum height (making sure that if 0 comes then we will break our prefixcnt=0)
        vector<int>prefix(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>row(n,0);
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    prefix[j]=0;
                }
                else
                {
                    prefix[j]+= 1;
                    row[j]= prefix[j];
                }
            }
            ans= max(ans,largestRectangleArea(row));
        }
        return ans;
    }
};
/*
    //METHOD-1
    //BRUTE FORCE..
    int largestRectangleArea(vector<int>& heights) 
    {
        int n= heights.size();
        vector<int>prevsmallidx(n,-1);
        stack<int>st;
        for(int i=0;i<n;i++)
        {
            while(st.size() && heights[st.top()]>=heights[i])
            {
                st.pop();
            }
            if(!st.empty())
            {
                prevsmallidx[i]= st.top();
            }
            st.push(i);//placing idx only..
        }

        vector<int>nextsmallidx(n,n);
        stack<int>st2;
        for(int i=n-1;i>=0;i--)
        {
            while(st2.size() && heights[st2.top()]>=heights[i])
            {
                st2.pop();
            }
            if(!st2.empty())
            {
                nextsmallidx[i]= st2.top();
            }
            st2.push(i);//placing idx only..
        }

        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans= max(ans,(heights[i])*(nextsmallidx[i]-prevsmallidx[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) 
    {
        int ans=0;
        int m= matrix.size();
        int n= matrix[0].size();
        //compute prefix column sum height (making sure that if 0 comes then we will break our prefixcnt=0)
        vector<int>prefix(n,0);
        for(int i=0;i<m;i++)
        {
            vector<int>row(n,0);
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]=='0')
                {
                    prefix[j]=0;
                }
                else
                {
                    prefix[j]+= 1;
                    row[j]= prefix[j];
                }
            }
            ans= max(ans,largestRectangleArea(row));
        }
        return ans;
    }
*/