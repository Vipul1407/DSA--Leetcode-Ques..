class Solution {
public:
    
    // METHOD-3
    //More Readable.. 
    // TC=O(M+N)
    string shiftingLetters(string s, vector<vector<int>>& shifts) 
    {
        int n= s.size();
        vector<int>change(n,0);
        for(auto i:shifts)
        {
            int l= i[0];
            int r= i[1];
            int dir= i[2];
            //forward shifting by 1..
            if(dir==1)
            {
                change[l]++;
                //will add opposite at index r+1 only if it is valid index..
                if(r+1<n)
                {
                    change[r+1]--;
                }
            }
            else
            {
                change[l]--;
                //will add opposite at index r+1 only if it is valid index..
                if(r+1<n)
                {
                    change[r+1]++;
                }
            }
        }
        //taking final prefix sum of change array..
        for(int i=1;i<n;i++)
        {
            change[i]+= change[i-1];

        }
        //updating string s...
        for(int i=0;i<n;i++)
        {
            int netchange= change[i]%26;
            if(netchange<0)
            {
                netchange+=26;
            }
            s[i]= 'a'+(s[i]-'a'+netchange)%26;
        }
        return s;
    }
};
/*
// METHOD-1
// BRUTE FORCE
// TC= O(M*N)
string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.size();
    for (auto i : shifts)
    {
        int l = i[0];
        int r = i[1];
        int dir = i[2];
        // we have to do shifting for all elements present in that range..
        for (int k = l; k <= r; k++)
        {
            // backward shifting..
            if (dir == 0)
            {
                s[k] = 'a' + (s[k] - 'a' - 1 + 26) % 26;
            }
            // forward shifting..
            else
            {
                s[k] = 'a' + (s[k] - 'a' + 1) % 26;
            }
        }
    }
    return s;
}

// METHOD-2
// TC=O(M+N)
// BEATS 30%
string shiftingLetters(string s, vector<vector<int>> &shifts)
{
    int n = s.size();
    vector<int> change(n, 0);
    for (auto i : shifts)
    {
        int l = i[0];
        int r = i[1];
        int dir = i[2];
        // forward shifting by 1..
        if (dir == 1)
        {
            change[l]++;
            // will add opposite at index r+1 only if it is valid index..
            if (r + 1 < n)
            {
                change[r + 1]--;
            }
        }
        else
        {
            change[l]--;
            // will add opposite at index r+1 only if it is valid index..
            if (r + 1 < n)
            {
                change[r + 1]++;
            }
        }
    }
    // taking final prefix sum of change array.. and updating string s
    int netchange = (change[0] % 26 + 26) % 26;
    s[0] = 'a' + (s[0] - 'a' + netchange) % 26;
    for (int i = 1; i < n; i++)
    {
        change[i] += change[i - 1];
        int netchange = (change[i] % 26 + 26) % 26;
        s[i] = 'a' + (s[i] - 'a' + netchange) % 26;
    }
    return s;
}
*/