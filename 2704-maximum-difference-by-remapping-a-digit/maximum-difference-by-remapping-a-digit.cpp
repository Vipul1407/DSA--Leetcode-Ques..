class Solution {
public:
    int minMaxDifference(int num) 
    {
        string maxi= to_string(num);
        string mini= to_string(num);
        int n= maxi.size();

        char max_replace;
        char min_replace;
        for(int i=0;i<n;i++)
        {
            if(maxi[i]!='9')
            {
                max_replace= maxi[i];
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(mini[i]!='0')
            {
                min_replace= mini[i];
                break;
            }
        }
        for(int d=0;d<n;d++)
        {
            if(maxi[d]==max_replace)
            {
                maxi[d]= '9';
            }
            if(mini[d]==min_replace)
            {
                mini[d]='0';
            }
        }
        return stoi(maxi)-stoi(mini);
    }
};