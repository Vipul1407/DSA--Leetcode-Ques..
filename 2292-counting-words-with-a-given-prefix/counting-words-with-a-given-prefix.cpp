class Solution {
public:
    int prefixCount(vector<string>& words, string pref) 
    {
        int cnt=0;
        int n= words.size();
        int m= pref.size();
        for(int i=0;i<n;i++)
        {
            string str= words[i].substr(0,m);
            if(str==pref)
            {
                cnt++;
            }
        }
        return cnt;
    }
};