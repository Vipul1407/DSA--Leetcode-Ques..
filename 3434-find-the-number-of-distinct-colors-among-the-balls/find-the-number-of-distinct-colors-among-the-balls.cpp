class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& quer) 
    {
        unordered_map<int,int>bc;// storing ball--color
        unordered_map<int,int>mpcnt;//storing color--cnt
        vector<int>ans;
        for(auto i:quer)
        {
            int ball= i[0];
            int color= i[1];
            //ball phle se present h to uske prev color ka cnt minus kr..
            if(bc.find(ball)!=bc.end())
            {
                int prevcolor= bc[ball];
                mpcnt[prevcolor]--;
                if(mpcnt[prevcolor]==0)
                {
                    mpcnt.erase(prevcolor);
                }
            }
            bc[ball]= color;
            mpcnt[color]++;
            ans.push_back(mpcnt.size());
        }
        return ans;
    }
};