class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        sort(begin(trainers),end(trainers));    
        sort(begin(players),end(players));

        int i=0,j=0,ans=0;
        while(i<players.size() && j<trainers.size())
        {
            while(trainers[j]<players[i])
            {
                j++;
                if(j==trainers.size())
                {
                    return ans;
                }
            }
            ans++;
            i++;j++;
        }
        return ans;
    }
};