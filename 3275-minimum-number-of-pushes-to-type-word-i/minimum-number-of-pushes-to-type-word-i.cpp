class Solution {
public:

    int minimumPushes(string word) 
    {
        int ans=0;
        for(int i=0;i<word.size();i++)
        {
            ans+= (1+i/8);
        }
        return ans;
    }
};