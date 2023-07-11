//* https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
//* https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/editorial/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        //* Method-1 : dividing into segments
        return method_1(nums);

        //* Method-2 : using Two pointers
        return method_2(nums);
    }
    int method_1(vector<int>& nums){
        int n = nums.size();

        int check = 1;
        int prev_seg_cnt = 0;
        // previous segment count
        int i;
        for(i = 0; i < n; i++){
            if(nums[i] == 0){
                break;
            }
            prev_seg_cnt++;
        }
        // all 1's
        if(prev_seg_cnt == n){
            return n-1;
        }

        nums.push_back(0); // ensures there will be a check at last
        int max_seg = 0, curr_seg_cnt = 0;;
        i++;
        while(i <= n){
            if(nums[i] == 0){
                max_seg = max(max_seg, prev_seg_cnt + curr_seg_cnt);
                prev_seg_cnt = curr_seg_cnt;
                curr_seg_cnt = 0;
            }
            else{
                curr_seg_cnt++;
            }
            i++;
        }

        return max_seg;
    }

    int method_2(vector<int>& nums){
        int n = nums.size();

        int i = 0, j = 0;
        int ans = 0;
        int zero = 0;

        while(j < n){
            if(nums[j] == 0){
                if(zero == 0){
                    zero = 1;
                }
                else{
                    while(i < j && zero){
                        if(nums[i] == 0){
                            i++;
                            break;
                        }
                        i++;
                    }
                }
            }

            ans = max(ans, j-i);
            j++;
        }

        return ans;
    }
};