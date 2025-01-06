class Solution {
public:
    //METHOD-4
    //OPTIMIZED.. without using extra space
    //TC=O(N)  SC=O(1)
    vector<int> minOperations(string boxes) 
    {
        int n= boxes.size();
        vector<int>ans(n,0);
        int leftp=0;
        int leftpsum=0;
        //Taking left--->
        for(int i=0;i<n;i++)
        {
            //here we will directly use =
            ans[i]= leftpsum;
            leftp+= (boxes[i]-'0');
            leftpsum+= leftp;
        }
        int rightp=0;
        int rightpsum=0;
        //Taking right--->
        for(int i=n-1;i>=0;i--)
        {
            //here we will use +=
            ans[i]+= rightpsum;
            rightp+= (boxes[i]-'0');
            rightpsum+= rightp;
        }
        return ans;
    }
};
/*
// METHOD-1
//  BRUTE FORCE
//  TC=O(N^2)
vector<int> minOperations(string boxes)
{
    vector<int> index;
    int n = boxes.size();
    for (int i = 0; i < n; i++)
    {
        if (boxes[i] == '1')
        {
            index.push_back(i);
        }
    }
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (auto idx : index)
        {
            cnt += abs(idx - i);
        }
        ans[i] = cnt;
    }
    return ans;
}

// METHOD-2
// BRUTE FORCE..
//  TC=O(N^2)
vector<int> minOperations(string boxes)
{
    int n = boxes.size();
    vector<int> ans(n, 0);
    for (int i = 0; i < n; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            if (boxes[j] == '1')
            {
                cnt += abs(i - j);
            }
        }
        ans[i] = cnt;
    }
    return ans;
}

// METHOD-3
//OPTIMIZED..
//  TC=O(4N)  SC=O(N)
vector<int> minOperations(string boxes)
{
    int n = boxes.size();
    vector<int> leftpref(n, 0);
    vector<int> rightpref(n, 0);
    vector<int> ans(n, 0);
    // forming left prefix array...
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += boxes[i] - '0';
        leftpref[i] = sum;
    }
    // forming right prefix array...
    sum = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += boxes[i] - '0';
        rightpref[i] = sum;
    }
    // we need ans[i]= sum of leftpref from 0 to i-1 + sum of rightpref from i+1 to n
    // here finding sum of leftpref upto i-1
    sum = 0;
    for (int i = 1; i < n; i++)
    {
        sum += leftpref[i - 1];
        ans[i] += sum;
    }
    // here finding sum of rightpref upto i+1
    sum = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        sum += rightpref[i + 1];
        ans[i] += sum;
    }
    return ans;
}
*/