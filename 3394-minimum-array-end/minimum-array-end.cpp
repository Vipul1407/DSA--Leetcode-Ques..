class Solution {
public:
    long long minEnd(int n, int x) {
        vector<int> shifts;  // Positions of 0-bits in x
        long long cur = x;   // Start with the value of x
        long long calc = n - 1;
        
        // Store all 0-bit positions of x up to the maximum necessary position.
        for(int i = 0; i < 64; i++) {
            if (!((1LL << i) & x)) {  // Use long long for shifting to prevent overflow
                shifts.push_back(i);
            }
        }
        
        // Increment cur using positions in shifts based on bits in calc
        for(int i = 0; calc > 0; i++, calc >>= 1) {
            if (calc & 1) {
                cur += (1LL << shifts[i]);  // Use long long for shifting to avoid overflow
            }
        }
        return cur;
    }
};

/*
class Solution {
public:
    long long minEnd(int n, int x) 
    {
        //to get the next value whose and value is same as x
        //so our 1st no. is x for 2nd
        //we will take x+1 and take OR of x and x+1
        //for 3rd no. we will take the above result and OR with x+2
        //and so on..

        n--;//as our 1st no. is x itself
        long long ans= x;
        while(n>0)
        {
            ans= (ans+1)|x;
            n--;
        }
        return ans;
    }
};
*/