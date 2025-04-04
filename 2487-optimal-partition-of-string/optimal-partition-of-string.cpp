class Solution {
public:
    int partitionString(string s) 
    {
        int n= s.size();
        int cnt=0;
        int start=0;
        vector<int>mp(26,-1);
        for(int i=0;i<n;i++)
        {
            int idx= mp[s[i]-'a'];
            //agar mp me phle se present h and mp[s[i]-'a]>=start then do cnt++; start=i; 
            if(idx!=-1 && idx>=start)
            {
                cnt++;
                start=i;
            }
            //agar mp me present ni h to mp[s[i]-'a]=i;
            mp[s[i]-'a']=i;
        }
        return cnt+1;
    }
}; 