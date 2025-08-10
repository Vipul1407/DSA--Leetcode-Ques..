class Solution {
public:
    //METHOD-2
    //TC= O(N) using set...
    bool reorderedPowerOf2(int n) 
    {
        set<vector<int>>st;
        for(int p=0;p<=29;p++)
        {
            int powertwo= (1<<p);
            vector<int>vec(10,0);
            while(powertwo>0)
            {
                int d= powertwo%10;
                vec[d]++;
                powertwo/=10;
            }
            st.insert(vec);
        }
        vector<int>vec(10,0);
        while(n>0)
        {
            int d= n%10;
            vec[d]++;
            n/=10;
        }
        return st.find(vec)!=st.end();
    }
};
/*
    //METHOD-1
    //TC= O(NLOGN) using sorting...
    bool reorderedPowerOf2(int n) 
    {
        for(int p=0;p<=29;p++)
        {
            string powertwo= to_string(1<<p);
            sort(begin(powertwo),end(powertwo));
            string str= to_string(n);
            sort(begin(str),end(str));
            if(powertwo==str)
            {
                return true;
            }
        }
        return false;
    }
};
*/