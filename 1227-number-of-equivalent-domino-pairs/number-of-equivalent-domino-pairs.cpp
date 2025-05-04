class Solution {
public:
    //METHOD-2
    //Using Const space of vector of size=99
    int numEquivDominoPairs(vector<vector<int>>& dominoes) 
    {
        int n= dominoes.size();
        int ans=0;
        //maxsize can go to 9*10+9= 99
        vector<int>vec(100,0);
        for(auto i:dominoes)
        {
            if(i[1]<i[0])
            {
                int key= i[1]*10+i[0];
                vec[key]++;
            }
            else
            {
                int key= i[0]*10+i[1];
                vec[key]++;
            }
        }
        for(auto i:vec)
        {
            //find nc2
            ans+= i*(i-1)/2;
        }
        return ans;
    }
};
/*
    //METHOD-1
    //Using Unordered Map..
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
*/