class Solution {
public:
    int minOperations(vector<string>& logs) 
    {
        int cnt=0;
        for(auto i:logs)
        {
            if(i=="./")
            {
                continue;
            }
            else if(i=="../")
            {
                if(cnt >0) cnt--;
            }
            else
            {
                cnt++;
            }
        } 
        return cnt;
    }
};