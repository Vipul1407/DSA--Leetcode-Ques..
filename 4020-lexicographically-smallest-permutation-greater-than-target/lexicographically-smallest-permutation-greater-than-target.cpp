class Solution {
public:
    //freq must not be called  by &
    string maxsuff(vector<int>freq)
    {
        string str="";
        for(int i=25;i>=0;i--)
        {
            while(freq[i]>0)
            {
                str+= 'a'+i;
                freq[i]--;
            }
        }
        return str;
    }
    //freq must not be called  by &
    //path must be called by &
    bool dfs(int i,bool same,string &path, int &n, vector<int>freq, string &tar)
    {
        if(i==n)
        {
            return !same;
        }
        //We have already make ut string greater now we have to place remainging char lexicographically smaller..
        if(!same)
        {
            for(int k=0;k<26;k++)
            {
                while(freq[k]>0)
                {
                    path+= 'a'+k;
                    freq[k]--;
                }
            }
            return true;
        }
        //if same==true then we can only place a char>=tar[i]
        for(int k=0;k<26;k++)
        {
            if(freq[k]==0)
            {
                continue;
            }
            char ch= 'a'+k;
            if(ch<tar[i])
            {
                continue;
            }
            freq[k]--;
            path.push_back(ch);

            //agar vo element ch ke same tha ..
            if(ch==tar[i])
            {
                string maxi= maxsuff(freq);
                string tarsuff= tar.substr(i+1);
                //agar still possible h..
                if(maxi>tarsuff)
                {
                    if(dfs(i+1,true,path,n,freq,tar))
                    {
                        return true;
                    }
                }
            }
            else
            {
                if(dfs(i+1,false,path,n,freq,tar))
                {
                    return true;
                }
            }
            //backtracking....
            path.pop_back();
            freq[k]++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string tar) 
    {
        vector<int>freq(26,0);
        int n= tar.size();
        for(auto i:s)
        {
            freq[i-'a']++;
        }
        string path;
        if(dfs(0,true,path,n,freq,tar))
        {
            return path;
        }
        //not possible..
        return "";
    }
};