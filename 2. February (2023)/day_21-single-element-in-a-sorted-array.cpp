//* https://leetcode.com/problems/single-element-in-a-sorted-array/description/
//* https://leetcode.com/problems/single-element-in-a-sorted-array/submissions/902363133/
//* https://www.geeksforgeeks.org/find-the-element-that-appears-once-in-a-sorted-array/

class Solution {
public:
    // int rec(vector<int>& nums, int low, int high){
    //     if(low == high){
    //         return nums[low];
    //     }
    //     int mid = (low + high) / 2;
    //     if (mid % 2 == 0) {
    //         if (nums[mid] == nums[mid + 1])
    //             return rec(nums, mid + 2, high);
    //         else
    //             return rec(nums, low, mid);
    //     }
    
    //     else {
    //         if (nums[mid] == nums[mid - 1])
    //             return rec(nums, mid + 1, high);
    //         else
    //             return rec(nums, low, mid - 1);
    //     }
    // }
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }

        // recursive solution->
        // return rec(nums,0, n-1);

        // Iterative Solution->
        int low = 0, high = n-1;
        while(low < high){
            int mid = (low + high)/ 2;

            if (mid % 2 == 0) {
                if (nums[mid] == nums[mid + 1]){
                    low = mid + 1;
                }
                else{
                    if(mid>0 && nums[mid] != nums[mid-1]){
                        return nums[mid];
                    }
                    high = mid -1;
                }
            }

            else {
                if (nums[mid] == nums[mid - 1]){
                    low = mid + 1;
                }
                else{
                    if(mid < (n-1) && nums[mid] != nums[mid+1]){
                        return nums[mid];
                    }
                    high = mid - 1;
                }
            }
        }
        return nums[low];
    }
};