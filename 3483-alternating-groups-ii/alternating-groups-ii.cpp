class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) 
    {
        int n= colors.size();
        int ans=0;
        int i=0;
        int j=1;
        for(int i=0;i<k-1;i++)
        {
            colors.push_back(colors[i]);
        }
        while(j<n+k-1)
        {
            if(colors[j-1]==colors[j])
            {
                i=j;
                j++;
                continue;
            }
            if(j-i+1==k)
            {
                ans++;
                i++;
            }
            j++;
        }
        return ans;
    }
};