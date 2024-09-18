class Solution {
public:
    long long smallestNumber(long long num) 
    {
        if(num==0)
        {
            return 0;//becoz stoll will give error for 0
        }
        bool neg= num<0? true:false;
        string ans="";
        if(neg)
        {
            //max heap..
            priority_queue<int>pq;
            num= abs(num);
            while(num>0)
            {
                pq.push(num%10);
                num/=10;
            }
            ans+='-';
            while(pq.size())
            {
                ans+=to_string(pq.top());
                pq.pop();
            }
        }
        else
        {
            //min heap..
            priority_queue<int,vector<int>,greater<int>>pq;
            while(num>0)
            {
                pq.push(num%10);
                num/=10;
            }
            ans+='+';
            int cnt=0;
            while(pq.size())
            {
                while(pq.top()==0 && ans=="+")
                {
                    cnt++;
                    pq.pop();
                }
                ans+=to_string(pq.top());
                pq.pop();
                while(cnt>0 && (ans!="" || ans!="+"))
                {
                    ans+='0';
                    cnt--;
                }
            }
        }
        return stoll(ans);
    }
};