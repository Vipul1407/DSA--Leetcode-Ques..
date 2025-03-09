class Solution {
public:
    //METHOD-2
    //SIMPLE APPROACH
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        int n= colors.size();
        int len=0;
        int ans=0;
        int prev=-1;
        for(auto i:colors)
        {
            if(prev==-1 || prev!=i)
            {
                len++;
                if(len>=k)
                {
                    ans++;
                }
            }
            else
            {
                len=1;
            }
            prev=i;
        }
        for(int i=0;i<k-1;i++)
        {
            if(colors[i]!=prev)
            {
                len++;
                if(len>=k)
                {
                    ans++;
                }
            }
            else
            {
                len=1;
            }
            prev= colors[i];
        }
        return ans;
    }
};
/*
// METHOD-1
// SLIDING WINDOW..
int numberOfAlternatingGroups(vector<int> &colors, int k)
{
    int n = colors.size();
    int ans = 0;
    int i = 0;
    int j = 1;
    // pushing starting k-1 elements to last to maintain circular order..
    for (int i = 0; i < k - 1; i++)
    {
        colors.push_back(colors[i]);
    }
    while (j < n + k - 1)
    {
        if (colors[j - 1] == colors[j])
        {
            i = j;
            j++;
            continue;
        }
        if (j - i + 1 == k)
        {
            ans++;
            i++;
        }
        j++;
    }
    return ans;
}
*/