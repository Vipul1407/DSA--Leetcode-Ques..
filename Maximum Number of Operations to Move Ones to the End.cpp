#include<stdio.h>
using namespace std;

class Solution 
{
public:
    int maxOperations(string s) 
    {
        int ones=0,ans=0,n=s.size();
        for(int i=0;i<n;i++)
        {
            //increase the count of 1..
            if(s[i]=='1')
            {
                ones++;
            }
            //if curr element is 0 and its prev is 1 then increase ans..
            else if(i>0 && s[i-1]=='1')
            {
                ans+= ones;
            }
        }
        return ans;
    }
};
/*
    //MY WRONG APPROACH..

    // int maxOperations(string s) 
    // {
    //     int n= s.size();
    //     int i= n-1;
    //     int last= n-1;
    //     int ans=0;
    //     while(i>=0)
    //     {
    //         if(s[i]=='1')
    //         {
    //             ans+= (last-i)>0? 1:0;
    //             last--;
    //         }
    //         i--;
    //     }    
    //     return ans;
    // }
*/