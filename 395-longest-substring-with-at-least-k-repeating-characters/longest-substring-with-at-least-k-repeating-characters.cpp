class Solution {
public:
    int longestSubstring(string s, int k) {
        if (s.size() < k) return 0;

        // Step 1: Count the frequency of each character in the string
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        // Step 2: Find the character with the minimum frequency
        char c = '\0';
        int minFreq = INT_MAX;
        for (auto &p : freq) {
            if (p.second < minFreq) {
                minFreq = p.second;
                c = p.first;
            }
        }

        // Step 3: If all characters meet the frequency condition, return the length of the string
        if (minFreq >= k) return s.size();

        // Step 4: Split the string by the character with minimum frequency and process recursively
        int maxLen = 0;
        stringstream ss(s);
        string segment;
        while (getline(ss, segment, c)) {
            maxLen = max(maxLen, longestSubstring(segment, k));
        }

        return maxLen;
    }
};
/*
//BRUTE FORCE...
class Solution {
public:
    int longestSubstring(string s, int k) 
    {
        int n= s.size();
        if(n<k)
        {
            return 0;
        }
        if(k<=1)
        {
            return n;
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            vector<int>vec(26,0);
            for(int j=i;j<n;j++)
            {
                vec[s[j]-'a']++;
                bool valid= true;
                for(int s:vec)
                {
                    if(s>0 && s<k)
                    {
                        valid= false;
                        break;
                    }
                }
                if(valid)
                {
                    ans= max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};

*/