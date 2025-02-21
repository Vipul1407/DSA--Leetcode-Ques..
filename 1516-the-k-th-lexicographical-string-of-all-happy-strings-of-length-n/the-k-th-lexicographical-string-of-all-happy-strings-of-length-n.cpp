class Solution {
public:
    // METHOD-1
    // BRUTE FORCE Using vector to store all the strings..
    void solve(string &str, char prev, int n, vector<string>&vec)
    {
        if(n==0)
        {
            vec.push_back(str);
            return;
        }
        for(char ch='a';ch<='c';ch++)
        {
            if(prev==ch)
            {
                continue;
            }
            str.push_back(ch);
            solve(str,ch,n-1,vec);
            str.pop_back();
        }
    }
    string getHappyString(int n, int k) 
    {
        vector<string>vec;
        string str;
        solve(str,'*',n,vec);
        if(k>vec.size())
        {
            return "";
        }
        return vec[k-1];
    }
};
/*
//  METHOD-2
//  OPTIMIZED
// Taking cnt in recursive calls...
void solve(int &cnt, string str, string &ans, char prev, int n, int &k)
{
    if (n == 0)
    {
        cnt++;
        if (cnt == k)
        {
            ans = str;
        }
        return;
    }
    for (char ch = 'a'; ch <= 'c'; ch++)
    {
        if (prev == ch)
        {
            continue;
        }
        str.push_back(ch);
        solve(cnt, str, ans, ch, n - 1, k);
        str.pop_back();
    }
}
string getHappyString(int n, int k)
{
    string ans;
    int cnt = 0;
    solve(cnt, "", ans, '*', n, k);
    return ans;
}

*/