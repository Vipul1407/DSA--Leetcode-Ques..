class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        int n= s.size();
        vector<int>ans;
        vector<int>mp(26,-1);
        for(int i=0;i<n;i++)
        {
            mp[s[i]-'a']=i;
        }
        int i=0;
        while(i<n)
        {
            int start=i;
            int j=i;
            while(i<=j)
            {
                j= max(j,mp[s[i]-'a']);
                i++;
            }
            ans.push_back(j-start+1);
        }   
        return ans;
    }
};