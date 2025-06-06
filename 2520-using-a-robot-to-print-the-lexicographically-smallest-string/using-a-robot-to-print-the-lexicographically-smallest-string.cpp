class Solution {
public:
    string robotWithString(string s) 
    {
        string ans="";
        int n= s.size(); 
        vector<char>rightmin(n,0);
        rightmin[n-1]= s[n-1];
        for(int i=n-2;i>=0;i--)
        {
            rightmin[i]= min(s[i],rightmin[i+1]);
        }    

        string temp="";
        temp.push_back(s[0]);
        char mini= s[0];
        for(int i=1;i<n;i++)
        {
            mini= rightmin[i];
            while(temp!="" && temp.back()<=mini)
            {
                ans+= temp.back();
                temp.pop_back();
            } 
            temp.push_back(s[i]);
        }
        reverse(temp.begin(),temp.end());
        ans+= temp;
        return ans;
    }
};