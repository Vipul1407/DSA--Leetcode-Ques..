class Solution {
public:
    bool isvowel(char ch)
    {
        if(ch=='a' || ch=='A' || ch=='e' || ch=='E' || ch=='i' || ch=='I' || ch=='o' || ch=='O' || ch=='u' || ch=='U')
        {
            return true;
        }
        return false;
    }
    bool isValid(string word) 
    {
        int n= word.size();
        if(n<3)
        {
            return false;
        }    
        int x=0,y=0;
        for(int i=0;i<n;i++)
        {
            if(!isalnum(word[i]))
            {
                return false;
            }
            else if(isvowel(word[i]))
            {
                x++;
            }
            else if(!isdigit(word[i]))
            {
                y++; 
            }
        }
        return x>0 && y>0;
    }
};