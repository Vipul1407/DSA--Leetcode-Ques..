class Solution {
public:
    //function to get max beauty of item coressponding to price q
    int binarysearch(vector<vector<int>>& items,int q)
    {
        int s=0;
        int e= items.size()-1;
        int ans=0;
        while(s<=e)
        {
            int mid= s+(e-s)/2;
            //if curr price is less than q
            if(items[mid][0]<=q)
            {
                ans= items[mid][1];//update ans to curr beauty
                s= mid+1;//search for more big beauty 
            }
            else
            {
                e= mid-1;//try for less beauty
            }
        }
        return ans;
    }
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& quer) 
    {
        vector<int>vec;
        int n=items.size();
        //must step..
        sort(items.begin(),items.end());
        int maxb=-1;
        //updating to keep a prefix of maximum beauty
        for(int i=0;i<n;i++)
        {
            maxb= max(maxb,items[i][1]);
            items[i][1]=maxb;
        }
        //apply logic..
        for(auto q:quer)
        {
            vec.push_back(binarysearch(items,q));
        }
        return vec;
    }
};