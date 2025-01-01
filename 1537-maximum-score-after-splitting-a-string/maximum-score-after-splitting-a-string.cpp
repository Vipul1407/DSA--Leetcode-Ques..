class Solution {
public:
    int maxScore(string s) 
    {
        int n=s.size();
        //storing 1 from right...
        vector<int>pref(n,0); 
        pref[n-1]= (s[n-1]=='1')? 1:0;
        for(int i=n-2;i>=0;i--)
        {
            if(s[i]=='1')
            {
                pref[i]=pref[i+1]+1;
            }
            else
            {
                pref[i]=pref[i+1];
            }
        } 
        int score=0;
        int zeros=0;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]=='0')
            {
                zeros++;
            }
            score= max(score,zeros+pref[i+1]);
        }
        return score;
    }
};