//* https://leetcode.com/problems/minimum-size-subarray-sum/
//* https://leetcode.com/problems/minimum-size-subarray-sum/editorial

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;

        int i = 0, j = 0, n = nums.size();
        long long sum = 0;
        while(j < n){
            sum += nums[j];

            while(i <= j && sum >= target){
                ans = min(ans, j-i+1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return ans == INT_MAX? 0 : ans;
    }
};