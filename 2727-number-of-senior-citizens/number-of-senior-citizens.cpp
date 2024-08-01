class Solution {
public:
    int countSeniors(vector<string>& details) 
    {
        int cnt=0;
        for(auto i:details)
        {
            string s= i.substr(11,2);
            if(stoi(s)>60)
            {
                cnt++;
            }
        }
        return cnt;
    }
};