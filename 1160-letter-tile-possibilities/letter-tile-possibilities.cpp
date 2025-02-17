class Solution {
public:
    //METHOD-2
    //Tracking cnt of characters...
    //Backtracking..
    void solve(string &tiles, vector<int>&cnt, int &ans)
    {
        for(int i=0;i<26;i++)
        {
            if(cnt[i]==0)
            {
                continue;
            }
            ans++;
            cnt[i]--;
            solve(tiles,cnt,ans);

            cnt[i]++;
        }
    }
    int numTilePossibilities(string tiles) 
    {
        int n= tiles.size();
        int ans=0;
        vector<int>cnt(26,0);
        for(auto i:tiles)
        {
            cnt[i-'A']++;
        }
        solve(tiles,cnt,ans);
        return ans;
    }
};

/*
//WRONG CODE..
// IF WE ONLY WANT SUBSET THEN CODE----
int solve(int i, string temp, string &tiles, unordered_set<string> &st)
{
    if (i >= tiles.size())
    {
        if (temp != "" && st.find(temp) == st.end())
        {
            st.insert(temp);
            return 1;
        }
        return 0;
    }
    int cnt = 0;
    if (temp != "" && st.find(temp) == st.end())
    {
        st.insert(temp);
        cnt = 1;
    }
    cnt += solve(i + 1, temp + tiles[i], tiles, st);
    cnt += solve(i + 1, temp, tiles, st);
    return cnt;
}
int numTilePossibilities(string tiles)
{
    unordered_set<string> st;
    return solve(0, "", tiles, st);
}

// BUT HERE WE WANT SUBSET+ PERMUTATION...
// METHOD-1
// BACKTRACKING..
void solve(string temp, vector<int> &used, string &tiles, unordered_set<string> &st)
{
    if (temp != "")
    {
        st.insert(temp);
    }

    for (int i = 0; i < tiles.size(); i++)
    {
        if (used[i])
        {
            continue;
        }
        used[i] = 1;
        temp.push_back(tiles[i]);
        solve(temp, used, tiles, st);

        temp.pop_back();
        used[i] = 0;
    }
}
int numTilePossibilities(string tiles)
{
    int n = tiles.size();
    unordered_set<string> st;
    vector<int> used(n, 0);
    solve("", used, tiles, st);
    return st.size();
}
*/