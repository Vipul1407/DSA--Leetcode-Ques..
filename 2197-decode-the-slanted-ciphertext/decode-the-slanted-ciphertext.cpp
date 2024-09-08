class Solution {
public:
    string decodeCiphertext(string encoded, int row) 
    {
        if(row==1)
        {
            return encoded;
        }
        int n= encoded.length();
        int col= n/row;
        vector<vector<char>>mat(row,vector<char>(col,' '));
        int k=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                mat[i][j]=encoded[k++];
            }
        }
        string original="";
        //traversing upto col length
        for(int k=0;k<col;k++)
        {
            int i=0;
            int j=k;
            while(i<row && j<col)
            {
                original+= mat[i][j];
                i++;
                j++;
            }
        }
        //to remove trailing spaces...
        while(!original.empty() && original.back()==' ')
        {
            original.pop_back();
        }
        return original;
    }
};