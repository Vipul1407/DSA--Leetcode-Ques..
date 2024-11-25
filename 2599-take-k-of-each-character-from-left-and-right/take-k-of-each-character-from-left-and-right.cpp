class Solution {
public:
    int takeCharacters(string s, int k) 
    {
        vector<int>freq(3,0);
        for(auto i:s)
        {
            freq[i-'a']++;
        }    
        if(freq[0]<k || freq[1]<k || freq[2]<k)
        {
            return -1;
        }
        int i=0;
        int j=0;
        int n= s.length();
        int ans=0;
        //we wnat a max window that can be non-deleted and initially..
        while(j<n)
        {
            freq[s[j]-'a']--;
            while(i<=j && (freq[0]<k || freq[1]<k || freq[2]<k))
            {
                freq[s[i]-'a']++;
                i++;
            }
            ans= max(ans,j-i+1);
            j++;
        }
        //deleted...
        return n-ans;
    }
};