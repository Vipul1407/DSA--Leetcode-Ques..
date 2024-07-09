class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) 
    {
        int n= capital.size();
        vector<pair<int,int>>vec;
        for(int i=0;i<n;i++)
        {
            vec.push_back({capital[i],profit[i]});
        }
        sort(vec.begin(),vec.end());

        //max heap for storing profit based on capital
        priority_queue<int>pq;
        int totalp=w;
        int j=0;

        while(k>0)
        {
            while(j<n && vec[j].first<=totalp)
            {
                pq.push(vec[j].second);
                j++;
            }
            if(pq.size()==0)
            {
                break;
            }
            totalp+= pq.top();
            pq.pop();
            k--;
        }
        return totalp;
    }
};