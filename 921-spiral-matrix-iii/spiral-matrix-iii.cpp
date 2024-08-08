class Solution {
public:
    //TC= O(MAX(row,col)^2)
    vector<vector<int>> spiralMatrixIII(int row, int col, int rs, int cs) 
    {
        //dir= EAST(0)-->SOUTH(1)-->WEST(2)-->NORTH(3)
        vector<pair<int,int>>index={{0,1},{1,0},{0,-1},{-1,0}};

        vector<vector<int>>mat;
        mat.push_back({rs,cs});
        int steps=0;
        int dir=0;//initial dir is east
        while(mat.size()<row*col)
        {
            //when we will go EAST OR WEST then will do steps+1
            if(dir==0 || dir==2)
            {
                steps++;
            }
            for(int i=0;i<steps;i++)
            {
                rs+= index[dir].first;//adding x-coordinate
                cs+= index[dir].second;//adding y-coordinate
                if(rs>=0 && rs<row && cs>=0 && cs<col)
                {
                    mat.push_back({rs,cs});
                }
            }
            dir= (dir+1)%4;
        }
        return mat;
    }
};