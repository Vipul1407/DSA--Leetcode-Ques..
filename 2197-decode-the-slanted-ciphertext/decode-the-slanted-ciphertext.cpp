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
        map<int,vector<char>>mp;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(i-j<=0)
                {
                    mp[i-j].push_back(mat[i][j]);
                }
            }
        }
        for(auto i=mp.rbegin();i!=mp.rend();i++)
        {
            for(auto j:i->second)
            {
                original+=j;
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