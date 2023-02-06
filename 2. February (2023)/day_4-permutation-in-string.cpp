//* https://leetcode.com/problems/permutation-in-string/

class Solution
{
    public:
    bool checkInclusion(string s1, string s2)
    {
        int l1 = s1.length();
        int l2 = s2.length();

        if(l2 < l1){
            return false;
        }

        sort(begin(s1), end(s1));

        int i=0;
        while(i < l2){
            size_t found = s1.find(s2[i]);

            if(found != string::npos && (i + (l1-1)) < l2)
            {
                string temp = s2.substr(i, l1);
                sort(begin(temp), end(temp));
                if(s1.compare(temp) == 0){
                    return true;
                }
            }

            i++;
        }
        return false;
    }
};