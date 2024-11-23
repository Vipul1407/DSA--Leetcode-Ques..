class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) 
    {
        int m= box.size();
        int n= box[0].size();
        int x=0,y=0;
        vector<vector<char>>vec(n,vector<char>(m,'.'));
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(box[i][j]=='#')
                {
                    cnt++;
                }
                else if(box[i][j]=='*')
                {
                    //new row = col
                    //new col = m-1-row
                    vec[j][m-1-i]='*';
                    //if we get a obstacle '*' then-----
                    //place '#' going upwards (x--)
                    x=j-1;
                    y=m-1-i;
                    while(cnt>0)
                    {
                        vec[x][y]='#';
                        cnt--;
                        x--;
                    }
                }
            }
            //if wall occur (end of row)---
            //place '#' going upwards (x--)
            x=n-1;
            y=m-1-i;
            while(cnt>0)
            {
                vec[x][y]='#';
                cnt--;
                x--;
            }
        }
        return vec;
    }
};