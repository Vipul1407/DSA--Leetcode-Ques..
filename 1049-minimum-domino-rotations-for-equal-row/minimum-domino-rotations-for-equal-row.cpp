class Solution {
public:
    //METHOD-1
    //2PASS 
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) 
    {
        int n= tops.size();
        int swaps= INT_MAX;
        for(int val=1;val<=6;val++)
        {
            //making top having all elements same..
            bool tf=true;
            int top=0;
            for(int i=0;i<n;i++)
            {
                if(tops[i]!=val)
                {
                    if(bottoms[i]==val)
                    {
                        top++;
                    }
                    else
                    {
                        tf= false;
                        break;
                    }
                }
            }
            
            //making bottom having all elements same..
            int bot=0;
            bool bf=true;
            for(int i=0;i<n;i++)
            {
                if(bottoms[i]!=val)
                {
                    if(tops[i]==val)
                    {
                        bot++;
                    }
                    else
                    {
                        bf= false;
                        break;
                    }
                }
            }
            if(tf)
            {
                swaps= min(swaps,top);
            }
            if(bf)
            {
                swaps= min(swaps,bot);
            }
        }
        return swaps==INT_MAX? -1:swaps;
    }
};