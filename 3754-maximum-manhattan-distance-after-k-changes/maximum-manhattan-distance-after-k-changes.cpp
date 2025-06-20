class Solution {
public:
    //Approach.. MIK
    int maxDistance(string s, int k) 
    {
        int n= s.size(); 
        int ans=0;
        int east=0,west=0,north=0,south=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='E')
            {
                east++;
            }
            else if(s[i]=='W')
            {
                west++;
            }
            else if(s[i]=='N')
            {
                north++;
            }
            else if(s[i]=='S')
            {
                south++;
            }
            int manhattan= abs(east-west)+abs(north-south);
            int steps= i+1;
            int extra= steps-manhattan;
            if(extra!=0)
            {
                extra= min(2*k,extra);
            }
            ans=max(ans, manhattan+extra);
        } 
        return ans;
    }
};