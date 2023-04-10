//* https://leetcode.com/problems/minimize-maximum-of-array/description/
//* https://leetcode.com/problems/minimize-maximum-of-array/editorial/
//* https://www.youtube.com/watch?v=AeHMvcKuR0Y&ab_channel=NeetCodeIO
//* https://www.youtube.com/watch?v=xDN7LSSmvDU&ab_channel=CodeFreaks

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        // Initialize answer and the prefix sum.
        long long answer = 0, prefixSum = 0;
        
        // Iterate over nums, update prefix sum and answer.
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += nums[i];
            answer = max(answer, (prefixSum + i) / (i + 1));
        }
        
        return answer;
    }
};