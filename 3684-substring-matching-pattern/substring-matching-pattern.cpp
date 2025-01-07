class Solution {
public:
    bool hasMatch(string s, string p) 
    {
        int x= p.find('*');
        //left string before '*'
        string left= p.substr(0,x);
        //right string after '*'
        string right= p.substr(x+1);
        //finding index of left from left side....
        int l= s.find(left);
        //finding index of right from right side... not from leftside by using rfind instead of find
        int r= s.rfind(right);
        //left substring bhi mile && right bhi present ho && dono overlapp na kre(means same substring ko hi cnt na krle)
        return l!=-1 && r!=-1 && l+left.size()<=r;
    }
};

