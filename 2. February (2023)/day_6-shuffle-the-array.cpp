//* https://leetcode.com/problems/shuffle-the-array/
//* https://leetcode.com/problems/shuffle-the-array/submissions/892455163/

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answer(2*n);
        int i = 0, j= n, k=0;
        while(i < n){
            answer[k] = nums[i]; i++, k++;
            answer[k] = nums[j]; j++, k++;
        }

        return answer;
    }
};