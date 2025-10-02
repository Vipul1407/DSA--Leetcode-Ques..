class Solution {
public:
    //MOST OPTIMIZED..
    // METHOD-4
    // WITHOUT USING STACK + 2 PASS..
    int largestRectangleArea(vector<int>& heights)
    {
        int n = heights.size();

        // next smaller..
        vector<int> nse(n);
        nse[n - 1] = n;
        for (int i = n - 2; i >= 0; i--)
        {
            int next = i + 1;
            while (next < n && heights[next] >= heights[i])
            {
                next = nse[next];
            }
            nse[i] = next;
        }

        // prev smaller..
        vector<int> pse(n, -1);
        pse[0] = -1;
        // finding ans....
        int ans = heights[0] * nse[0];
        for (int i = 1; i < n; i++)
        {
            int prev = i - 1;
            while (prev >= 0 && heights[prev] >= heights[i])
            {
                prev = pse[prev];
            }
            pse[i] = prev;
            ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        vector<vector<int>>arr(m,vector<int>(n,0));
        for(int j=0;j<n;j++)
        {
            int prefix=0;
            for(int i=0;i<m;i++)
            {
                if(mat[i][j]=='1')
                {
                    prefix++;
                }
                else
                {
                    prefix=0;
                }
                arr[i][j]= prefix;
           }
        }
        int ans=0;
        for(int i=0;i<m;i++)
        {
            ans= max(ans,largestRectangleArea(arr[i]));
        }
        return ans;
    }
};
/*
//  METHOD-1
//  BRUTE FORCE..
//  3 PASS + STACK..
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // prev smaller..
    vector<int> pse(n, -1);
    stack<int> st1;
    st1.push(-1);
    for (int i = 0; i < n; i++)
    {
        while (st1.top() != -1 && heights[st1.top()] >= heights[i])
        {
            st1.pop();
        }
        pse[i] = st1.top();
        st1.push(i);
    }

    // next smaller..
    vector<int> nse(n, n);
    stack<int> st2;
    st2.push(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st2.top() != n && heights[st2.top()] >= heights[i])
        {
            st2.pop();
        }
        nse[i] = st2.top();
        st2.push(i);
    }

    // finding ans..
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
    }
    return ans;
}

// METHOD-2
// 2 PASS ONLY + STACK..
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // next smaller..
    vector<int> nse(n, n);
    stack<int> st2;
    st2.push(n);
    for (int i = n - 1; i >= 0; i--)
    {
        while (st2.top() != n && heights[st2.top()] >= heights[i])
        {
            st2.pop();
        }
        nse[i] = st2.top();
        st2.push(i);
    }

    // prev smaller + finding ans....
    vector<int> pse(n, -1);
    stack<int> st1;
    st1.push(-1);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        while (st1.top() != -1 && heights[st1.top()] >= heights[i])
        {
            st1.pop();
        }
        pse[i] = st1.top();
        st1.push(i);
        ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
    }
    return ans;
}

// METHOD-3
// WITHOUT USING STACK + 3 PASS..
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // prev smaller..
    vector<int> pse(n, -1);
    pse[0] = -1;
    for (int i = 1; i < n; i++)
    {
        int prev = i - 1;
        while (prev >= 0 && heights[prev] >= heights[i])
        {
            prev = pse[prev];
        }
        pse[i] = prev;
    }

    // next smaller..
    vector<int> nse(n);
    nse[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
    {
        int next = i + 1;
        while (next < n && heights[next] >= heights[i])
        {
            next = nse[next];
        }
        nse[i] = next;
    }

    // finding ans....
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
    }
    return ans;
}

// METHOD-4
// WITHOUT USING STACK + 2 PASS..
int largestRectangleArea(vector<int> &heights)
{
    int n = heights.size();

    // next smaller..
    vector<int> nse(n);
    nse[n - 1] = n;
    for (int i = n - 2; i >= 0; i--)
    {
        int next = i + 1;
        while (next < n && heights[next] >= heights[i])
        {
            next = nse[next];
        }
        nse[i] = next;
    }

    // prev smaller..
    vector<int> pse(n, -1);
    pse[0] = -1;
    // finding ans....
    int ans = heights[0] * nse[0];
    for (int i = 1; i < n; i++)
    {
        int prev = i - 1;
        while (prev >= 0 && heights[prev] >= heights[i])
        {
            prev = pse[prev];
        }
        pse[i] = prev;
        ans = max(ans, heights[i] * (nse[i] - pse[i] - 1));
    }
    return ans;
}

// OLD APPROACHES...................................................
//  METHOD-2
//  OPTIMIZED...
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

// METHOD-1
// BRUTE FORCE..
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

    vector<int> nextsmallidx(n, n);
    stack<int> st2;
    for (int i = n - 1; i >= 0; i--)
    {
        while (st2.size() && heights[st2.top()] >= heights[i])
        {
            st2.pop();
        }
        if (!st2.empty())
        {
            nextsmallidx[i] = st2.top();
        }
        st2.push(i); // placing idx only..
    }

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, heights[i] * (nextsmallidx[i] - prevsmallidx[i] - 1));
    }
    return ans;
}
*/