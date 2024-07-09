class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profit, vector<int>& capital) 
    {
        priority_queue<int>maxheap;
        int n= capital.size();

        //minheap storing cost, profit
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minheap; 
        int totalp=w;//initialized with w

        for(int i=0;i<n;i++)
        {
            minheap.push({capital[i],profit[i]});
        }
        while(k>0)
        {
            while(!minheap.empty() && minheap.top().first<= totalp)
            {
                maxheap.push(minheap.top().second);
                minheap.pop();
            }
            if(maxheap.size()==0)
            {
                break;
            }
            totalp+= maxheap.top();
            maxheap.pop();
            k--;
        }
        return totalp;
    }
};