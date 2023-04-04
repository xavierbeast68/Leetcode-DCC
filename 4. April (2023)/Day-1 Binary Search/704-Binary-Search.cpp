//* https://leetcode.com/problems/binary-search/description/
//* https://leetcode.com/problems/binary-search/editorial/
//* https://www.youtube.com/watch?v=8AUsxW6cu-Q&ab_channel=CodeFreaks

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size()-1;
        while(low <= high){
            int mid = low + (high-low)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        
        return -1;
    }
};