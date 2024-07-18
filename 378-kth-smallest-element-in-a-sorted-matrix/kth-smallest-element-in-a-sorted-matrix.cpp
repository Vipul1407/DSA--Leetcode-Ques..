class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) 
    {
        //Given that n=m
        int n= matrix.size();
        // int m= matrix[0].size();

        //MIN HEAP taking advantage that elements are sorted
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        //value, row, col

        //pushing first value of each row
        for(int i=0;i<n;i++)
        {
            pq.push({matrix[i][0],i,0});
        }
        int cnt=0;
        int ans=0;
        while(cnt<k)
        {
            auto curr= pq.top();
            pq.pop();
            ans= curr[0];
            int row= curr[1];
            int col= curr[2];
            cnt++;

            if(col+1<n)
            {
                pq.push({matrix[row][col+1],row,col+1});
            }
        }
        return ans;
    }
};