class Solution {
public:
    void solve(string temp, vector<int>&used, string &tiles, unordered_set<string>&st)
    {
        if(temp!="")
        {
            st.insert(temp);
        }

        for(int i=0;i<tiles.size();i++)
        {
            if(used[i])
            {
                continue;
            }
            used[i]= 1;
            temp.push_back(tiles[i]);
            solve(temp,used,tiles,st);

            temp.pop_back();
            used[i]= 0;
        }
    }
    int numTilePossibilities(string tiles) 
    {
        int n= tiles.size();
        unordered_set<string>st;
        vector<int>used(n,0);
        solve("",used,tiles,st);
        return st.size();
    }
};