class Solution {
public:
    string removeKdigits(string num, int k) 
    {
        stack<char>st;
        for(char i:num)
        {
            while(!st.empty() && k>0 && (st.top()-'0')>(i-'0'))
            {
                st.pop();
                k--;
            }
            //to handle that case where no. is like 12345
            st.push(i);
        }
        while(k>0)
        {
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty())
        {
            ans+= st.top();//to get reversed string so that can access back element and pop it 
            st.pop();
        }
        //to remove leading zeros in final string 
        //we have reversed string so if any leading zero present then it will be at back
        while(!ans.empty() && ans.back()=='0')
        {
            ans.pop_back();
        }
        if(ans=="")
        {
            return "0";
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};