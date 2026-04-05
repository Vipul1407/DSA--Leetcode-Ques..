class Solution {
public:
    bool judgeCircle(string moves) 
    {
        int hor=0;
        int ver=0;
        for(auto i:moves)
        {
            if(i=='U')
            {
                ver++;
            }
            else if(i=='D')
            {
                ver--;
            }
            else if(i=='L')
            {
                hor--;
            }
            else if(i=='R')
            {
                hor++;
            }
        }
        return (ver==0 && hor==0);
    }
};