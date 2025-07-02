class Solution {
public:
    vector<int>dx={0,1,0,-1};
    vector<int>dy={1,0,-1,0};
    bool solve(int i,int j,int k,vector<vector<char>>& board, string &word)
    {
        if(k==word.size())
        {
            return true;
        }
        char temp= board[i][j];
        board[i][j]='*';
        for(int dir=0;dir<4;dir++)
        {
            int x= i+dx[dir];
            int y= j+dy[dir];

            if(x<0 || y<0 || x>=board.size() || y>=board[0].size() || board[x][y]=='*')
            {
                continue;
            }
            if(board[x][y]==word[k])
            {
                if(solve(x,y,k+1,board,word))
                {
                    return true;
                }
            }
        }
        //backtracking..
        board[i][j]= temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) 
    {
        int m= board.size();
        int n= board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]== word[0])
                {
                    //start with index=1
                    if(solve(i,j,1,board,word))
                    {
                        return true;
                    }
                }
            }
        }  
        return false;  
    }
};