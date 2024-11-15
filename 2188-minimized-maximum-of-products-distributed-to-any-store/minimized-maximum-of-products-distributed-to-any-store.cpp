class Solution {
public:
    bool possible(int k, vector<int>& quan, int mid)
    {
        int cnt=0;
        for(auto i:quan)
        {
            //cnt+= (i+mid-1)/mid;
            cnt+= ceil((float)(i)/mid);
        }
        return cnt<=k;
    }
    int minimizedMaximum(int K, vector<int>& quan) 
    {
        int s= 1;//min space needed is 1
        int e= *max_element(quan.begin(),quan.end());//max space needed is max value in quan
        int ans=0;
        while(s<=e)
        {
            int mid= (s+e)/2;
            if(possible(K,quan,mid))
            {
                ans= mid;
                e= mid-1;//search to get min ans
            }
            else
            {
                s= mid+1;//try for max ans
            }
        }
        return ans;
    }
};