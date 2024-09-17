class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) 
    {   
        vector<string>ans;
        unordered_map<string,int>mp;
        string form="";
        string str= s1+" "+s2;
        for(auto i:str)
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