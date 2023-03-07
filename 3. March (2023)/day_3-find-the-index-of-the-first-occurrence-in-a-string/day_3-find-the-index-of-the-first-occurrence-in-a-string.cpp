//* https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/description/

class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.length(), l2 = needle.length();

        if(l1 < l2){
            return -1;
        }
        if(l1 == l2){
            if(haystack.compare(needle) != 0){
                return -1;
            } else{
                return 0;
            }
        }

        for(int i = 0 ; i < l1 - l2 + 1; ++i){
            if(haystack[i] == needle[0]){
                string temp = haystack.substr(i, l2);
                if(temp.compare(needle) == 0){
                    return i;
                }
            }
        }

        return -1;
    }
};