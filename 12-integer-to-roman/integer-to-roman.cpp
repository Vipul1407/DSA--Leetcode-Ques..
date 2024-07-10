class Solution
{
public:
    /*
        I-  1
        IV- 4
        V-  5
        IX- 9
        X-  10
        XL- 40
        L-  50
        XC- 90
        C-  100
        CD- 400
        D-  500
        CM- 900
        M-  1000
    */
    string intToRoman(int num)
    {
        string ans = "";
        // we will start from last
        while (num >= 1000)
        {
            ans += "M";
            num -= 1000;
        }
        while (num >= 900)
        {
            ans += "CM";
            num -= 900;
        }
        while (num >= 500)
        {
            ans += "D";
            num -= 500;
        }
        while (num >= 400)
        {
            ans += "CD";
            num -= 400;
        }
        while (num >= 100)
        {
            ans += "C";
            num -= 100;
        }
        while (num >= 90)
        {
            ans += "XC";
            num -= 90;
        }
        while (num >= 50)
        {
            ans += "L";
            num -= 50;
        }
        while (num >= 40)
        {
            ans += "XL";
            num -= 40;
        }
        while (num >= 10)
        {
            ans += "X";
            num -= 10;
        }
        while (num >= 9)
        {
            ans += "IX";
            num -= 9;
        }
        while (num >= 5)
        {
            ans += "V";
            num -= 5;
        }
        while (num >= 4)
        {
            ans += "IV";
            num -= 4;
        }
        while (num >= 1)
        {
            ans += "I";
            num -= 1;
        }
        return ans;
    }
};