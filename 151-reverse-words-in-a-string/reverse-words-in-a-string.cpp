class Solution {
public:
    //METHOD-1
    //Using StringStream
    string reverseWords(string str) 
    {
        stringstream ss(str);
        string temp;
        vector<string>vec;

        //it will ignore leading and trailing spaces... as we are not uing getline()
        while(ss>>temp)
        {
            vec.push_back(temp);
        }
        string ans="";
        while(vec.size()>1)
        {
            ans+= vec.back();
            ans+=' ';
            vec.pop_back();
        }
        ans+= vec.back();
        return ans;
    }
};