class Solution {
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& quer) 
    {
        int n= words.size();
        vector<int>pref(n,0);
        for(int i=0;i<n;i++)
        {
            char front= words[i].front();
            char back= words[i].back();
            if((front=='a'||front=='e'||front=='i'||front=='o'||front=='u')&&(back=='a'||back=='e'||back=='i'||back=='o'||back=='u'))
            {
                pref[i]=1;
            }
           if(i>0)
           {
                pref[i]+=pref[i-1];
           }
        }
        vector<int>res;
        for(int i=0;i<quer.size();i++)
        {
            int r= quer[i][1];
            int l= quer[i][0];
            if(l==0)
            {
                res.push_back(pref[r]);
            }
            else
            {
                res.push_back(pref[r]-pref[l-1]);
            }
        }
        return res;
    }
};