//* https://leetcode.com/problems/kth-missing-positive-number/description/
//* https://www.youtube.com/watch?v=DpEMbKwHJKQ

class Solution {
public:
    
    int findKthPositive(vector<int>& arr, int k) {
        // brute-force solution-> O(max_element(arr) + k)
        // int count = 0, ans = 0;
        // int i = 0, j = 1;
        // while(k && i < arr.size()){
        //     if(j != arr[i]){
        //         k--;
        //         if(k == 0){
        //             ans = j;
        //             break;
        //         }
        //     }
        //     else{
        //         ++i;
        //     }
        //     ++j;
        // }
        // while(k){
        //     k--;
        //     if(k == 0){
        //         ans = j;
        //         break;
        //     }
        //     j++;
        // }
        // return ans;

        // optimised-> O(log n) using binary search

        int low = 0, high = arr.size();
        while(low < high){
            int mid = low + (high - low)/2;

            if(arr[mid] - mid > k){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return high + k;

    }
};