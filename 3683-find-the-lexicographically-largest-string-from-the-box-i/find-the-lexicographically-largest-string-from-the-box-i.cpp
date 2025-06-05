class Solution {
public:
    //METHOD-1
    //TC= O(N^2)
    //SC= O(1)
    string answerString(string word, int friends) 
    {
        if(friends==1)
        {
            return word;
        }
        int n= word.size();
        int maxlen= n- friends+1;
        string ans="";
        for(int i=0;i<n;i++)
        {
            int maxtake= min(n-i,maxlen);
            ans= max(ans,word.substr(i,maxtake));
        }
        return ans;
    }
};