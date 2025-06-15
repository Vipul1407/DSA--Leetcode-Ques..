class Solution {
public:
    int maxDiff(int num) 
    {
        string maxi= to_string(num);
        string mini= to_string(num);
        int n= maxi.size();
        char maxi_replace;
        char mini_replace='*';
        char value_replace;

        for(auto i:maxi)
        {
            if(i!='9')
            {
                maxi_replace= i;
                break;
            }
        }
        for(int i=0;i<n;i++)
        {
            if(i==0 && mini[i]!='1')
            {  
                mini_replace= mini[i];
                value_replace='1';
                break;
            }
            //mini[0]='1'
            else if(i>0)
            {
                //becoz 0 ko replace krne ki jarurat ni h and
                //mini[0]='1' tha hi isliye 1 ko replace ni krenge..
                if(mini[i]!='1' && mini[i]!='0')
                {
                    mini_replace= mini[i];
                    value_replace='0';
                    break;
                }   
            }
        }
        for(int i=0;i<n;i++)
        {
            if(maxi[i]== maxi_replace)
            {
                maxi[i]= '9';
            }
            if(mini_replace!='*' && mini[i]== mini_replace)
            {
                mini[i]= value_replace;
            }
        }
        return stoi(maxi)-stoi(mini);
    }
};