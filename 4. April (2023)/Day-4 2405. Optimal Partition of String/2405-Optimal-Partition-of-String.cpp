//* https://leetcode.com/problems/optimal-partition-of-string/
//* https://leetcode.com/problems/optimal-partition-of-string/editorial/
//* https://www.youtube.com/watch?v=CKZPdiXiQf0&ab_channel=NeetCodeIO
//* https://www.youtube.com/watch?v=K9p6PJeT_DE&ab_channel=CodeFreaks

class Solution {
public:
    int partitionString(string s) {
        
        // Using Maps-> Space Complexity-> O(26)-> constant
        int cnt = 0;
        map<char, int> mp;
        int i = 0, j=0;
        int n = s.length();
        while(j<n){
            mp[s[j]]++;

            if(mp.size() != (j-i+1)){
                i = j;
                mp.clear();
                mp[s[j]]++;
                cnt++;
            }
            j++;
        }

        return cnt+1;
    }
};