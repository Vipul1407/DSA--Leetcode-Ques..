class Solution {
public:
    // METHOD-2
    // TC=O(N)
    // SC=O(1)
    // Without using any vector
    int maxScore(string s) 
    {
        int n=s.size();
        int ones=0;
        ones= count(s.begin(),s.end(),'1');
        int zeros=0;
        int score=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                zeros++;
            }
            else
            {
                ones--;//to get ones on left side only..
            }
            score= max(score,zeros+ones);
        }
        return score;
    }
};
/*
// METHOD-1
// TC=SC=O(N)
// Using prefix vector..
int maxScore(string s)
{
    int n = s.size();
    // storing 1 from right...
    vector<int> pref(n, 0);
    pref[n - 1] = (s[n - 1] == '1') ? 1 : 0;
    for (int i = n - 2; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            pref[i] = pref[i + 1] + 1;
        }
        else
        {
            pref[i] = pref[i + 1];
        }
    }
    int score = 0;
    int zeros = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == '0')
        {
            zeros++;
        }
        score = max(score, zeros + pref[i + 1]);
    }
    return score;
}
*/