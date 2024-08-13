class Solution 
{
public:

    vector<vector<int>>ans;
    //here we have to pass vec by reference &
    void solve(int i,vector<int>& cand,int k,vector<int>&vec)
    {
        if(k==0)
        {
            ans.push_back(vec);
            return;
        }
        if(k<0 || i==cand.size())
        {
            return;
        }
        for(int j=i;j<cand.size();j++)
        {
            if(j>i && cand[j]==cand[j-1])
            {
                continue;//to avoid duplicates repeatition of same vectors like {1,3,2} or {2,1,3}
                //we will avoid recursive call in that case
            }
            vec.push_back(cand[j]);
            //also do j+1 here becoz we have to take 1 number only 1 time
            solve(j+1,cand,k-cand[j],vec);
            vec.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& cand, int k) 
    {
        vector<int>vec;
        //to avoid duplicates or repeation--> we will sort and not start rec call from same element...
        sort(cand.begin(),cand.end());
        solve(0,cand,k,vec);
        
        return ans;  
    }
};