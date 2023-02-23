//* https://leetcode.com/problems/search-insert-position/description/
//* https://www.youtube.com/watch?v=K-RYzDZkzCI&ab_channel=NeetCode

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int ind=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return ind;
    }
};