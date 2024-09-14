class Solution {
public:
    bool winnerOfGame(string colors) 
    {
        int n= colors.size();
        int ca=0;//
        int wa=0;
        int cb=0;
        int wb=0;
        for(auto i:colors)
        {
            if(i=='A')
            {
                ca++;
                cb=0;
                if(ca>=3)
                {
                    wa++;
                }
            }
            else
            {
                cb++;
                ca=0;
                if(cb>=3)
                {
                    wb++;
                }
            }
        }
        //not wa>=wb becoz if both have same for eg. 0 then by default bob wins i.e false
        return wa>wb;
    }
};