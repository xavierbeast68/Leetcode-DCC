class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0 || (x%10==0 && x!=0))
        {
            return false;
        }
        int revnumber=0;
        while(x>revnumber)
        {
            revnumber=revnumber*10+x%10;
            x/=10;
        }
        return x==revnumber || x==revnumber/10;
    }
};