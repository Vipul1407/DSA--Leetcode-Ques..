class Solution {
public:
    //METHOD-2
    //SIMPLE APPROACH
    int numberOfAlternatingGroups(vector<int>& colors) 
    {
        int n= colors.size();
        colors.push_back(colors[0]);
        colors.push_back(colors[1]); 
        int ans=0,prev=-1,len=0;
        for(auto i:colors)
        {
            if(prev==-1 || i!=prev)
            {
                len++;
                if(len>=3)
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
        return ans;
    }
};
/*
//METHOD-1
// BRUTE FORCE..
// BEATS 88%
    int numberOfAlternatingGroups(vector<int>& colors) 
    {
        int n= colors.size();
        colors.push_back(colors[0]);
        colors.push_back(colors[1]); 
        int ans=0;
        for(int i=1;i<n+2;i++)
        {
            if(colors[i]!=colors[i-1] && colors[i]!=colors[i+1])
            {
                ans++;
            }
        }
        return ans;
    }
*/