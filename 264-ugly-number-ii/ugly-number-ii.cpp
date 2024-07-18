class Solution {
public:
    int nthUglyNumber(int n) 
    {
        //Min Heap
        priority_queue<int,vector<int>,greater<int>>pq;
        unordered_set<int>st;

        //since 1 is a ugly number
        pq.push(1);
        st.insert(1);

        int cnt=0;
        //we have to find next n-1 elements as 1 we have already found
        while(cnt<n-1)
        {
            long long top= pq.top();
            pq.pop();
            long long a= top*2;
            long long b= top*3;
            long long c= top*5;

            //set me a ni h to dal de dono me
            if(a<= INT_MAX && st.find(a)==st.end())
            {
                st.insert(a);
                pq.push(a);
            }
            if(b<= INT_MAX && st.find(b)==st.end())
            {
                st.insert(b);
                pq.push(b);
            }
            if(c<= INT_MAX && st.find(c)==st.end())
            {
                st.insert(c);
                pq.push(c);
            }
            cnt++;
        }
        return (int)pq.top();
    }
};