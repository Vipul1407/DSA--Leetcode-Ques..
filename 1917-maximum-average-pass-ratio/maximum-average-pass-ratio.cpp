class Solution {
public:
    // OPTIMIZED APPROACH..
    // Using Priority_queue
    // TC= O(ex*LOG(N))
    // SC=O(N)
    double maxAverageRatio(vector<vector<int>>& clas, int ex) 
    {
        int n= clas.size();
        //storing difference, index
        priority_queue<pair<double,int>>pq;
        for(int i=0;i<n;i++)
        {
            double a= (double)(clas[i][0])/clas[i][1];
            double b= (double)(clas[i][0]+1)/(clas[i][1]+1);
            pq.push({b-a,i});
        }

        while(ex-- && pq.size())
        {
            int idx= pq.top().second;
            pq.pop();
            //incremented above...
            // as we have already pushed diff,i in pq so need to update clas
            clas[idx][0]++;
            clas[idx][1]++;
            //for next iteration..
            double diff= (double)(clas[idx][0])/clas[idx][1];
            double newdiff= (double)(clas[idx][0]+1)/(clas[idx][1]+1);
            pq.push({newdiff-diff,idx});
        }
        double ans=0.0;
        for(int i=0;i<n;i++)
        {
            ans+= (double)(clas[i][0])/clas[i][1];
        }
        return ans/n;
    }
};
/*
// GREEDY...
// WRONG ANS..
// If we find ration and then add 1 in the ratio which is max then we will get wrong ans
// To get correct ans, we have to find the max chnage after adding 1

//  BRUTE FORCE..
//  TC=O(ex*N)
//  SC= O(N)
double maxAverageRatio(vector<vector<int>> &clas, int ex)
{
    int n = clas.size();
    vector<double> arr(n, 0.0);
    vector<double> newarr(n, 0.0);
    for (int i = 0; i < n; i++)
    {
        arr[i] = (double)(clas[i][0]) / clas[i][1];
    }
    while (ex--)
    {
        for (int i = 0; i < n; i++)
        {
            newarr[i] = (double)(clas[i][0] + 1) / (clas[i][1] + 1);
        }
        double diff = -1;
        int idx = 0;
        for (int i = 0; i < n; i++)
        {
            if (newarr[i] - arr[i] > diff)
            {
                diff = newarr[i] - arr[i];
                idx = i;
            }
        }
        arr[idx] = newarr[idx];
        clas[idx][0]++;
        clas[idx][1]++;
    }
    double ans = 0.0;
    for (auto i : arr)
    {
        ans += i;
    }
    return ans / n;
}
*/