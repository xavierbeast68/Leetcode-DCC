//* https://leetcode.com/problems/number-of-zero-filled-subarrays/description/
//* https://www.youtube.com/watch?v=22CfEGAetpQ

class Solution {
    public long zeroFilledSubarray(int[] nums) {
        long cnt = 0, ans = 0;
        int n = nums.length;
        for(int i = 0 ; i < n ; ++i){
            if(nums[i] == 0){
                cnt++;
            }
            else{
                ans += (cnt * (cnt+1) / 2);
                cnt = 0;
            }
        }
        if(cnt != 0){
            ans += (cnt * (cnt+1) / 2);
        }
        return ans;
    }
}