// VanAmsen : https://leetcode.com/problems/minimum-deletions-to-make-character-frequencies-unique/solutions/4033205/98-18-greedy-heap-sorting/?envType=daily-question&envId=2023-09-12
// AryanMittal : https://www.youtube.com/watch?v=sq7LBb6Kd3g&ab_channel=AryanMittal

class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26, 0);
        for(char ch : s){
            freq[ch-'a']++;
        }
        sort(freq.begin(), freq.end());

        stack<int> availableSizes;
        int n = s.length();
        for(int i = 1; i <= n; i++){
            availableSizes.push(i);
        }

        stack<int> neededSize;
        for(auto it : freq){
            neededSize.push(it);
        }

        int deletedChars = 0;
        while(availableSizes.size() != 0 && neededSize.size() != 0){
            int reqSize = neededSize.top();
            int availSize = availableSizes.top();

            if(availSize > reqSize){
                availableSizes.pop();
            }
            else if(availSize == reqSize){
                availableSizes.pop();
                neededSize.pop();
            }
            // availSize < reqSize
            else{
                deletedChars += (reqSize - availSize);
                availableSizes.pop();
                neededSize.pop();
            }
        }

        while(neededSize.size() != 0){
            deletedChars += neededSize.top();
            neededSize.pop();
        }

        return deletedChars;
    }
};