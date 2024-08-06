class Solution {
public:

    int minimumPushes(string word) 
    {
        vector<int>vec(26,0);
        //8-->single letter
        //8-->double digit
        //8-->triple digit
        //2-->4 digits
        for(auto i:word)
        {
            vec[i-'a']++;
        } 
        int cnt=0;
        int ans=0;
        for(int i=0;i<26;i++)
        {
            if(vec[i]==0)
            {
                continue;
            }
            cnt++;
            if(cnt<=8)
            {
                ans+=vec[i];
            }
            else if(cnt<=16)
            {
                ans+= vec[i]*2;
            }
            else if(cnt<=24)
            {
                ans+= vec[i]*3;
            }
            else
            {
                ans+= vec[i]*4;
            }
        }
        return ans;
    }
};