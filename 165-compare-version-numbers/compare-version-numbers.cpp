class Solution {
public:
    void fun(string &v, vector<string>&ans)
    {
        stringstream ss(v);
        string token="";
        while(getline(ss,token,'.'))
        {
            ans.push_back(token);
        }
    }
    int compareVersion(string v1, string v2) 
    {
        vector<string>ans1;
        vector<string>ans2;
        fun(v1,ans1);
        fun(v2,ans2);
        int i=0;
        int n= ans1.size(), m= ans2.size();
        while(i<n || i<m)
        {
            int a= i>=n? 0:stoi(ans1[i]);
            int b= i>=m? 0:stoi(ans2[i]);
            if(a<b)
            {
                return -1;
            }
            else if(a>b)
            {
                return 1;
            }
            else
            {
                i++;
            }
        }
        return 0;
    }
};