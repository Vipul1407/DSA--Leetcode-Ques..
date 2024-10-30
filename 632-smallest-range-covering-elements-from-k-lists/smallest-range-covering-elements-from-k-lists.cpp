class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) 
    {
        int k= nums.size();
        //min heap.. storing==>  {element, listindex, index}
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        int maxel= INT_MIN;
        for(int i=0;i<k;i++)
        {
            pq.push({nums[i][0],i,0});
            maxel= max(maxel,nums[i][0]);
        }
        vector<int>range={-100000,100000};
        while(pq.size())
        {
            vector<int>curr= pq.top();
            pq.pop();
            int minel= curr[0];
            int list= curr[1];
            int idx= curr[2];
            if(maxel-minel< range[1]-range[0])
            {
                range[1]= maxel;
                range[0]= minel;
            }
            if(idx+1< nums[list].size())
            {
                int nextel= nums[list][idx+1];
                pq.push({nextel,list,idx+1});
                maxel= max(maxel,nextel);
            }
            else
            {
                break;
            }
        }
        return range;
    }
};