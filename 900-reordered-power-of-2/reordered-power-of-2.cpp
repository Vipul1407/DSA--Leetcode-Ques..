class Solution {
public:
    //METHOD-3
    //TC= O(N) using set... storing string
    bool reorderedPowerOf2(int n) 
    {
        unordered_set<int>st;
        for(int p=0;p<=29;p++)
        {
            int powertwo= (1<<p);
            int val=0;
            while(powertwo>0)
            {
                int d= powertwo%10;
                val+= pow(10,d);
                powertwo/=10;
            }
            st.insert(val);
        }
        int num=0;
        while(n>0)
        {
            int d= n%10;
            num+= pow(10,d);
            n/=10;
        }
        return st.find(num)!=st.end();
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

    //METHOD-2
    //TC= O(N) using set...  storing vector<int>
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
*/