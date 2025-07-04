class Solution {
public:
    bool safe(int row,int col,char val,vector<vector<char>>& board)
    {
        int n= board.size();
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==val)
            {
                return false;
            }
            if(board[i][col]==val)
            {
                return false;
            }
            if(board[3*(row/3)+i/3][3*(col/3)+i%3]==val)
            {
                return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board) 
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    //placing a valid char..
                    for(char k='1';k<='9';k++)
                    {
                        if(safe(i,j,k,board))
                        {
                            board[i][j]= k;
                            //aage ki possibility..
                            if(solve(board))
                            {
                                return true;
                            }
                            //backtrack..
                            else
                            {
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) 
    {
        solve(board);
    }
};