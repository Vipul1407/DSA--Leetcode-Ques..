class Solution {
public:
    int hIndex(vector<int>& cit) 
    {
        sort(cit.begin(),cit.end());
        int cnt=0;
        int ans=0;
        int n=cit.size();
        for(int i=n-1;i>=0;i--)
        {
            if(cit[i]<cnt+1)
            {
                ans=cnt;
                break;
            }
            cnt++;
        }
        //to handle case when cit=[1] only
        if(ans==0)
        {
            ans=cnt;
        }
        return ans;
    }
};