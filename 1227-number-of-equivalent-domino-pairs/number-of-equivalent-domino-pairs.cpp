class Solution {
public:
    //METHOD-1
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        int n= dominoes.size();
        int ans=0;
        map<pair<int,int>,int>mp;
        for(auto i:dominoes)
        {
            if(i[1]<i[0])
            {
                mp[{i[1],i[0]}]++;
            }
            else
            {
                mp[{i[0],i[1]}]++;
            }
        }
        for(auto i:mp)
        {
            int cnt= i.second;
            //find nc2
            ans+= cnt*(cnt-1)/2;
        }
        return ans;
    }
};