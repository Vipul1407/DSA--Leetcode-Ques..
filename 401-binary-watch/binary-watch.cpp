class Solution {
public:
    int setbit(int num)
    {
        int cnt=0;
        while(num>0)
        {
            if(num & 1)
            {
                cnt++;
            }
            num>>=1;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int turnedOn) 
    {
        vector<string>ans;
        for(int i=0;i<12;i++)
        {
            for(int j=0;j<60;j++)
            {
                if(setbit(i)+setbit(j)==turnedOn)
                {
                    string temp= to_string(i);
                    temp+= ":";
                    if(j<10)
                    {
                        temp+= "0";
                    }
                    temp+= to_string(j);
                    ans.push_back(temp);
                }
            }
        }
        return ans;
    }
};