class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>>mat(n,vector<int>(n,0));
        int e=1;
        int left= 0;
        int right= n-1; 
        int top= 0;
        int down= n-1;
        while(top<=down && left<=right)
        {
            ///going right...
            for(int i=left;i<=right;i++)
            {
                mat[top][i]=e++;
            }
            top++;

            //going down...
            for(int i=top;i<=down;i++)
            {
                mat[i][right]=e++;
            }
            right--;

            //going left..
            if(top<=down)
            {
                for(int i=right;i>=left;i--)
                {
                    mat[down][i]=e++;
                }
                down--;
            }

            //going up..
            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                    mat[i][left]=e++;
                }
                left++;
            }
        }
        return mat;
    }
};