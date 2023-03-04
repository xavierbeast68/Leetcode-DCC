//* https://leetcode.com/problems/count-subarrays-with-fixed-bounds/description/
//* https://www.youtube.com/watch?v=zLv5H6CaTgE

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        int n = nums.size();

        bool minF = false, maxF = false;
        long res = 0;
        int start = 0, minStart = 0, maxStart = 0;
        for(int i = 0; i < n; ++i){

            int num = nums[i];

            if(num < minK || num > maxK){
                minF = false;
                maxF = false;
                start = i + 1;
            }

            if(num == minK){
                minF = true;
                minStart = i;
            }

            if(num == maxK){
                maxF = true;
                maxStart = i;
            }

            if(minF && maxF){
                res += (min(minStart, maxStart) - start + 1);
            }
        }

        return res;
    }
};