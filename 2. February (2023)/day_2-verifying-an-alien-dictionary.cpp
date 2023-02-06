//* https://leetcode.com/problems/verifying-an-alien-dictionary/

class Solution {
public:
    bool match(string s1, string s2, string order)
    {
        int l1=s1.size(), l2=s2.size();
        for(int i=0; i<l1; i++)
        {
            int p1 = order.find(s1[i]);
            int p2 = order.find(s2[i]);
            if(p1 < p2){
                return true;
            }
            if(p1 > p2){
                return false;
            }

            if(p1==p2 && i+1 == l2 && !(l1 == l2)){
                // apple, app
                return false;
            }
        }
        return true; // in case of p1 = p2 in all characters (app, app) or (app, apple)
    }
    bool isAlienSorted(vector<string>& words, string order) {
        int sz = words.size();
        for(int i=0; i<sz-1; i++)
        {
            if(!(match(words[i], words[i+1], order)))
            {
                return false;
            }
        }
        return true;
    }
};