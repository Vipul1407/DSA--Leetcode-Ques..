class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n= words.size();
        int ans= n+1;

        for(int i=0; i<n; i++)
        {
            if(words[i]== target)
            {
                int idx= abs(startIndex-i);
                ans= min(ans, min(idx, n-idx));
            }
        }
       return (ans== n+1) ? -1: ans; 
    }
};