class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector<string>ans;
        int n= s.size();
        string str="";
        for(int i=0;i<n;i+=k)
        {
            str+= s.substr(i,k);
            if(str.size()!=k)
            {
                int cnt= k-str.size();
                while(cnt--)
                {
                    str+= fill;
                }
            }
            ans.push_back(str);
            str="";
        }
        return ans;
    }
}; 