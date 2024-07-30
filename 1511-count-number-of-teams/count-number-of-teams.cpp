class Solution {
public:
    int numTeams(vector<int>& rating) 
    {
        int n= rating.size();
        int ans=0;
        for(int i=1;i<n-1;i++)
        {
            int curr= rating[i];
            int smalleft=0;
            int smallright=0;
            int greatleft=0;
            int greatright=0;
            for(int j=0;j<i;j++)
            {
                if(rating[j]<curr)
                {
                    smalleft++;
                }
                else if(rating[j]>curr)
                {
                    greatleft++;
                }
            }
            for(int k=i+1;k<n;k++)
            {
                if(rating[k]<curr)
                {
                    smallright++;
                }
                else if(rating[k]>curr)
                {
                    greatright++;
                }
            }
            ans+= smalleft*greatright+ smallright*greatleft;
        }
        return ans;
    }
};