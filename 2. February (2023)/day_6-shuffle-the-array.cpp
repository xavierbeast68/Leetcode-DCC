//* https://leetcode.com/problems/shuffle-the-array/
//* https://leetcode.com/problems/shuffle-the-array/submissions/892455163/
//* https://www.youtube.com/watch?v=IvIKD_EU8BY&ab_channel=NeetCodeIO
//* https://leetcode.com/problems/shuffle-the-array/solutions/2973933/shuffle-the-array/

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