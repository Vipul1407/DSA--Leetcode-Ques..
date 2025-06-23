# define ll long long
class Solution {
    // building 1st half (pre) + 2nd half
    ll solve(ll pre, int is_odd){
        ll tmp = pre;
        if(is_odd){tmp/=10;}

        while(tmp>0){
            pre = pre*10 + (tmp%10);  // 11 + 3 => 113? // 11*10 + 3 = 113
            tmp /= 10;
        }

        return pre;
    }
    // this will generate all palindrome for a given length
    vector<ll> kthPalindrome(int len) {
        vector<ll> ans;

        // 1st half length
        ll half = (len+1)/2 - 1;
        ll mn=1,mx=9;
        while(half--){
            mn = mn*10;
            mx = mx*10 + 9;
        }
        // cout<<mn<<" "<<mx;

        ll val = 0;
        while(1){
            ll pos = val;

            ll num = mn + pos;
            if(num > mx){
                break;
            }
            else{
                ll complete = solve(num, len%2);
                ans.push_back(complete);
            }
            val++;
        }

        return ans;
    }
    bool is_palin(ll num, int base) {        
        // convert to base
        string s = "";
        while (num > 0) {
            s += (char)((num % base) + '0');
            num /= base;
        }

        // Check if s is a palindrome
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i] != s[j]) {return false;}
            i++, j--;
        }

        return true;
    }
public:
    ll kMirror(int k, int n) {
        ll sum = 0;
        int cnt = 0;

        ll len = 1;

        for(int len = 1;len<12;len++){
            vector<ll> ele = kthPalindrome(len);

            for(auto& val:ele){
                if (is_palin(val, k)) {
                    // cout<<val<<" ";
                    sum += val;
                    cnt++;

                    if(cnt == n){return sum;}
                }
            }
        }        

        return sum;
    }
};