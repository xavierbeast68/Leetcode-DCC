//* https://leetcode.com/problems/buddy-strings/
// https://leetcode.com/problems/buddy-strings/editorial/

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }

        int swaps = 0;
        map<char,int> mps, mpgoal;

        for(int i = 0; i< s.size(); i++){
            if(s[i] != goal[i]){
                swaps++;
            }
            mps[s[i]]++;
            mpgoal[goal[i]]++;
        }

        if(swaps == 0){
            for(auto it : mps){
                if(it.second > 1){
                    return true;
                }
            }
            return false;
        }
        if(swaps > 2){
            return false;
        }

        for(auto it : mps){
            if(mpgoal.find(it.first) == mpgoal.end()){
                return false;
            }
            else if(mpgoal[it.first] != it.second){
                return false;
            }
        }

        return true;
    }
};