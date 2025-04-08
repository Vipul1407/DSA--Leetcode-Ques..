class Solution {
public:
    //METHOD-1
    //BRUTE FORCE..
    vector<string> findAllRecipes(vector<string>& rec, vector<vector<string>>& ing, vector<string>& supp) 
    {
        int n= rec.size();
        unordered_set<string>st;
        for(auto i:supp)
        {
            st.insert(i);
        }
        vector<string>ans;
        vector<int>cooked(n,0);
        int cnt=n;
        while(cnt--)
        {
            for(int i=0;i<n;i++)
            {
                if(cooked[i]==1)
                {
                    continue;
                } 
                bool canmake= true;
                for(int j=0;j<ing[i].size();j++)
                {
                    if(st.find(ing[i][j])==st.end())
                    {
                        canmake= false;
                        break;
                    }
                }
                if(canmake==true)
                {
                    cooked[i]=1;
                    st.insert(rec[i]);
                    ans.push_back(rec[i]);
                }
            }
        }
        return ans;
    }
};