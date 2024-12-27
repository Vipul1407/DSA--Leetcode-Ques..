class Solution {
public:
    //METHOD-3
    //Using Priority_queue
    int maxScoreSightseeingPair(vector<int>& values) 
    {
        int n= values.size();
        int ans= 0;
        //max heap for values[i]+i
        priority_queue<int>pq;
        pq.push(values[0]);
        for(int j=1;j<n;j++)
        {
            ans= max(ans, pq.top()+values[j]-j);
            pq.push(values[j]+j);
        }
        return ans;
    }
};
/*
// METHOD-1
// Using prefix max vector for arr[i]+i
int maxScoreSightseeingPair(vector<int> &values)
{
    int n = values.size();
    vector<int> pref(n, 0);
    pref[0] = values[0];
    for (int i = 1; i < n; i++)
    {
        pref[i] = max(pref[i - 1], values[i] + i);
    }
    int ans = 0;
    for (int j = 1; j < n; j++)
    {
        ans = max(ans, pref[j - 1] + values[j] - j);
    }
    return ans;
}

// METHOD-2
// Without using method, taking variable for max value of i+arr[i] at runtime...
int maxScoreSightseeingPair(vector<int> &values)
{
    int n = values.size();
    int ans = 0;
    int pref = values[0];
    for (int j = 1; j < n; j++)
    {
        ans = max(ans, pref + values[j] - j);
        pref = max(pref, values[j] + j);
    }
    return ans;
}
*/