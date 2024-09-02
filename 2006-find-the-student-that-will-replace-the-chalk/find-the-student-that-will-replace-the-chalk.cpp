class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) 
    {
        int n= chalk.size();
        long long sum=0;
        for(auto i:chalk)
        {
            sum+=i;
        }
        k%=sum;
        int i=0;
        while(true)
        {
            while(k>=chalk[i%n])
            {
                k-=chalk[i%n];
                i++;
            }
            if(k<0)
            {
                return i%n;
            }
            else 
            {
                return i%n;
            }
        }
        return 0;
    }
};