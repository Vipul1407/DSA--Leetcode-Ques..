class Solution {
public:
    // METHOD-2
    // OPTIMIZED
    // SLIDING WINDOW..
    int totalFruit(vector<int>& fruits) 
    {
        int n= fruits.size();
        int i=0,j=0;
        int ans=0;
        unordered_map<int,int>mp;
        while(j<n)
        {
            mp[fruits[j]]++;
            //shrink window..
            if(mp.size()>2)
            {
                mp[fruits[i]]--;
                if(mp[fruits[i]]==0)
                {
                    mp.erase(fruits[i]);
                }
                i++;
            }
            ans= max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};
/*
// Ques is same as Find substring with atmost 2 distinct char...
// METHOD-1
// BRUTE FORCE..
int totalFruit(vector<int> &fruits)
{
    int n = fruits.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        unordered_set<int> st;
        for (int j = i; j < n; j++)
        {
            st.insert(fruits[j]);
            if (st.size() <= 2)
            {
                ans = max(ans, j - i + 1);
            }
            else
            {
                break;
            }
        }
    }
    return ans;
}
*/