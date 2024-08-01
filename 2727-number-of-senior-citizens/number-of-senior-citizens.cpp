class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int cnt=0;
        for(auto i:details)
        {
            int d= (i[11]-'0')*10+(i[12]-'0');
            if(d>60)
            {
                cnt++;
            }
        }
        return cnt;
    }
};