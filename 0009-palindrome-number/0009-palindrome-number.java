class Solution {
    public boolean isPalindrome(int x) {
        if(x%10==0 && x>0){return false;}
        int temp=0;
        while(temp<x)
        {
            temp=temp*10 + x%10;
            x/=10;
        }
        return temp==x || (temp/10)==x;
    }
}