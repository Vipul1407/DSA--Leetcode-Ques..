class Solution {
public:
    string sortVowels(string s) 
    {
        vector<char>vow;
        int n= s.size();
        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u' || s[i]=='A'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                vow.push_back(s[i]);
            }
        }
        sort(rbegin(vow),rend(vow));

        for(int i=0;i<n;i++)
        {
            if(s[i]=='a'|| s[i]=='e' || s[i]=='i' || s[i]=='o'|| s[i]=='u' || s[i]=='A'|| s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U')
            {
                if(vow.empty())
                {
                    break;
                }
                s[i]= vow.back();
                vow.pop_back();
            }
        }
        return s;
    }
};