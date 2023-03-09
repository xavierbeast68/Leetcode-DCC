//* https://leetcode.com/problems/sort-an-array/
//* https://leetcode.com/problems/sort-an-array/solutions/3241851/simplest-solution-3-approaches-heap-sort-merge-sort-priority-queue-c/

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for(int i : nums){
            pq.push(i);
        }
        for(int i = 0 ; i < nums.size() ; ++i){
            nums[i] = pq.top();
            pq.pop();
        }
        return nums;
    }
};