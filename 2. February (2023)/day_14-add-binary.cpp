//* https://leetcode.com/problems/add-binary/description/
//* https://leetcode.ca/2016-02-05-67-Add-Binary/
//* https://www.youtube.com/watch?v=keuWJ47xG8g
//* https://www.youtube.com/watch?v=OEW50g03mT0
//* https://www.geeksforgeeks.org/program-to-add-two-binary-strings/

class Solution {
public:
    string addBinary(string a, string b) {
        string res;
        int i = a.length() - 1;
        int j = b.length() - 1;
        int carry = 0;
        while(i >= 0 || j >= 0){
            int sum = carry;
            if(i >= 0) sum += a[i--] - '0';
            if(j >= 0) sum += b[j--] - '0';
            carry = sum > 1 ? 1 : 0;
            res += to_string(sum % 2);
        }
        if(carry) res += to_string(carry);
        reverse(res.begin(), res.end());
        return res;



        // or
        // int i = a.size() - 1, j = b.size() - 1, carry = 0;
        // string ans;
        // while (i >= 0 || j >= 0 || carry) {
        //     if (i >= 0) carry += a[i--] - '0';
        //     if (j >= 0) carry += b[j--] - '0';
        //     ans += '0' + (carry & 1);
        //     carry >>= 1;
        // }
        // return string(rbegin(ans), rend(ans));
    }
};