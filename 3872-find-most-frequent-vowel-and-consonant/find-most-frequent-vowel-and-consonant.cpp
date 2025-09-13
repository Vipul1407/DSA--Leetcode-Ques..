class Solution {
public:
    int maxFreqSum(string s) 
    {
        int vow=0, cons=0;
        vector<int>freq(26,0);
        for(auto i:s)
        {
            freq[i-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            //a=0, e=4, i=8, o=14, u=20
            if(i==0 || i==4 || i==8 || i==14 || i==20)
            {
                vow= max(vow,freq[i]);
            }
            else
            {
                cons= max(cons,freq[i]);
            }
        }
        return vow+cons;
    }
};