class Solution {
public:
    //sorting of strings a,ab,cd,cf,cde will be-->
    //a,ab,cd,cde,cf based on lexicographical order..
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(),folder.end());
        vector<string>ans;

        //sorted h isliye folder[0] ka koi parent ni hoga
        ans.push_back(folder[0]);

        int n=folder.size();
        for(int i=1;i<n;i++)
        {
            string curr= folder[i];
            string last= ans.back();
            //this is added so to differentiate b/w a/b/c and a/b/ca
            //since a/b/ca is not a substring of a/b/c/ but it will be assumed as substring is we seee only a/b/c..
            last+='/';
            //agr currfolder substring ni h lastfolder ke to ans me include krenge..
            if(curr.find(last)!=0)
            {
                ans.push_back(curr);
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        vector<string>ans;
        unordered_set<string>uset(folder.begin(),folder.end());
        for(auto str:folder)
        {
            bool include=true;
            int n=str.size();
            int i=n-1;//starting form last index to find last '/'
            while(i>=0)
            {
                while(i>=0 && str[i]!='/')
                {
                    i--;
                }
                string sub= str.substr(0,i);
                //agar set me mila to ans me vo string ko include ni krenge..
                if(uset.find(sub)!=uset.end())
                {
                    include=false;
                    break;
                }
                //set me ni mila..
                else
                {
                    i--;//process repeat kr
                }
            }
            //flag true h mtlb set me ni mila kbhi hence ans me include krenge..
            if(include)
            {
                ans.push_back(str);
            }
        }
        return ans;
    }
};
*/