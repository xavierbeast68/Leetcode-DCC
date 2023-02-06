//* https://leetcode.com/problems/greatest-common-divisor-of-strings/

class Solution {
public:
    string joinwords(string base, int times){
        string ans = "";
        for(int i = 1; i <= times; i++)
        {
            ans += base;
        }
        return ans;
    }
    
    bool isValid(string str1, string str2, int k)
    {
        int len1 = str1.size(), len2 = str2.size();
        if(len1 % k ==0 && len2 % k ==0)
        {
            string base = str1.substr(0,k);
            int n1 = len1 / k, n2 = len2 / k;
            return str1 == joinwords(base, n1) && str2 == joinwords(base, n2);
        }
        return false;
    }
    
    string gcdOfStrings(string str1, string str2) {
        
        int len1 = str1.length(), len2 = str2.length();
        for (int i = min(len1, len2); i >= 1; --i)
        {
            if(isValid(str1, str2, i))
            {
                return str1.substr(0, i);
            }
        }
        return "";
    }
};