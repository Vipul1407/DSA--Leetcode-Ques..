class Solution {
public:
    //METHOD-3
    //SLIDING WINDOW..
    int numberOfAlternatingGroups(vector<int>& colors) 
    {
        int n= colors.size();
        colors.push_back(colors[0]);
        colors.push_back(colors[1]); 
        int i=0;
        int j=1;
        int ans=0;
        while(j<n+2)
        {
            if(colors[j-1]==colors[j])
            {
                i=j;
                j++;
                continue;
            }
            if(j-i+1==3)
            {
                ans++;
                i++;
            }
            j++;
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

//METHOD-2
//SIMPLE APPROACH
//BEATS 14%
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
*/