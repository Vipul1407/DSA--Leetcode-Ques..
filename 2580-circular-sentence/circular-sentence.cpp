class Solution {
public:
    bool isCircularSentence(string sent) 
    {
        vector<string>vec;
        stringstream ss(sent);
        string word;
        while(ss>>word)
        {
            vec.push_back(word);
        }
        int n= vec.size();
        if(n==1)
        {
            if(vec[0][0]!=vec[0].back())
            {
                return false;
            }
        }
        for(int i=1;i<n;i++)
        {
            if(vec[i-1].back()!=vec[i][0])
            {
                return false;
            }
        }
        if(vec[0][0]!=vec[n-1].back())
        {
            return false;
        }
        return true;
    }
};