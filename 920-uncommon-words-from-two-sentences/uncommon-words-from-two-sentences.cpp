class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {   
        vector<string>ans;
        unordered_map<string,int>mp;
        string form="";
        for(auto i:s1)
        {
            if(i==' ')
            {
                mp[form]++;
                form="";
            }
            else
            {
                form+=i;
            }
        }
        mp[form]++;
        form="";
        for(auto i:s2)
        {
            if(i==' ')
            {
                mp[form]++;
                form="";
            }
            else
            {
                form+=i;
            }
        }
        mp[form]++;
        
        for(auto i:mp)
        {
            if(i.second==1)
            {
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};