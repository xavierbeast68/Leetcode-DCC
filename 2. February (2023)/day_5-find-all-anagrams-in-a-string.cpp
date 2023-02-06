// https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/3143576/c-easy-solution-sliding-window-approach-heavily-commented/
// https://leetcode.com/problems/find-all-anagrams-in-a-string/solutions/3139748/easy-understandable-solution/

class Solution {
public:
bool isAnagram(int fs[],int fp[]){
        for(int i=0;i<26;i++){
            if(fs[i]!=fp[i]){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        int l1 = p.length();
        int l2 = s.length();
        vector<int> answer;

        // this will give TLE, as substr takes O(n) time
        // sort(begin(p), end(p));
        // int i=0;
        // while(i < l2-l1+1){
        //     size_t found = p.find(s[i]);

        //     if(found != string::npos && (i + (l1-1)) < l2)
        //     {   
        //         string temp = s.substr(i, l1);
        //         sort(begin(temp), end(temp));
        //         if(p.compare(temp) == 0){
        //             answer.push_back(i);
        //         }
        //     }

        //     i++;
        // }

        int fs[26]={0},fp[26]={0};
        for(int i=0;i<l1;i++){
            fp[p[i]-'a']++;
        }
        for(int i=0;i<l2;i++){
            if(i<l1-1){
                fs[s[i]-'a']++;
            }
            else if(i==l1-1){
                fs[s[i]-'a']++;
                if(isAnagram(fs,fp)){
                    answer.push_back(i-l1+1);
                }
            }
            else{
                fs[s[i-l1]-'a']--;
                fs[s[i]-'a']++;
                if(isAnagram(fs,fp)){
                    answer.push_back(i-l1+1);
                }
            }
        }
        return answer;
    }
};