class Solution {
public:
    //METHOD-3
    int minimumLength(string s) 
    {
        int ans=0;
        vector<int>vec(26,0);
        for(auto i:s)
        {
            vec[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(vec[i]==0)
            {
                continue;
            }
            //odd times..
            if(vec[i]%2==1)
            {
                ans++;
            }
            //even times..
            else
            {
                ans+=2;
            }
        }
        return ans;
    }
};
/*
// METHOD-1
int minimumLength(string s)
{
    vector<int> vec(26, 0);
    for (auto i : s)
    {
        vec[i - 'a']++;
        if (vec[i - 'a'] == 3)
        {
            vec[i - 'a'] -= 2;
        }
    }
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        if (vec[i] == 0)
        {
            continue;
        }
        ans += vec[i];
    }
    return ans;
}

// METHOD-2
int minimumLength(string s)
{
    vector<int> vec(26, 0);
    int ans = 0;
    for (auto i : s)
    {
        vec[i - 'a']++;
        if (vec[i - 'a'] == 3)
        {
            vec[i - 'a'] -= 2;
            ans += 2;
        }
    }
    return s.size() - ans;
}
*/