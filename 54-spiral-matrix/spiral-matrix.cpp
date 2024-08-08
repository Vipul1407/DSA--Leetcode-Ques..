class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& mat) 
    {
        int m= mat.size();
        int n= mat[0].size();
        int left=0;
        int right=n-1;
        int top=0;
        int down=m-1;
        vector<int>ans;
        //spiral order--> right down left top
        while(top<=down && left<=right)
        {
            //going right...
            for(int i=left;i<=right;i++)
            {
                ans.push_back(mat[top][i]);
            } 
            top++;
            //going down..
            for(int i=top;i<=down;i++)
            {
                ans.push_back(mat[i][right]);
            }
            right--;
            //going left..
            if(top<=down)
            {
                for(int i=right;i>=left;i--)
                {
                    ans.push_back(mat[down][i]);
                }
                down--;
            }
            //going up...
            if(left<=right)
            {
                for(int i=down;i>=top;i--)
                {
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        return ans;
    }
};