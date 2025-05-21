class Solution 
{
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<bool> row(m, false); // Step 1: Create row array
        vector<bool> col(n, false); // Step 1: Create col array

        // Step 2: Mark rows and columns that have a zero
        for(int i = 0; i < m; ++i) 
        {
            for(int j = 0; j < n; ++j) 
            {
                if(matrix[i][j] == 0) 
                {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }

        // Step 3: Set zeroes for marked rows
        for(int i = 0; i < m; ++i) 
        {
            if(row[i]) 
            {
                for(int j = 0; j < n; ++j)
                {
                    matrix[i][j] = 0;
                }
            }
        }

        // Step 4: Set zeroes for marked columns
        for(int j = 0; j < n; ++j) 
        {
            if(col[j]) 
            {
                for(int i = 0; i < m; ++i)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }
};