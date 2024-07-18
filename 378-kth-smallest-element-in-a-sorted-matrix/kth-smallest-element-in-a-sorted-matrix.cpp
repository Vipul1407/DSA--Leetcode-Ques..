class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        //Given that n=m
        int n= matrix.size();
        // int m= matrix[0].size();

        //MAX HEAP
        priority_queue<int>pq;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                pq.push(matrix[i][j]);
                cnt++;
                if(cnt>k)
                {
                    pq.pop();
                }
            }
        }
        return pq.top();
    }
};