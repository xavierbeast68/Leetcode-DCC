//* https://leetcode.com/problems/add-to-array-form-of-integer/description/
//* https://leetcode.com/problems/add-to-array-form-of-integer/submissions/898331628/

// Linear Time Complexity
// O(max(nums.size() , floor(log10(k)+1)) + 1)

class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        vector<int> ans;
        int carry = 0, n = num.size();

        int i = n-1;
        while( i >= 0 || k/10 > 0 || k%10 > 0 || carry){
            if(i >= 0) {
                carry += num[i];
                --i;
            }
            if(k/10 > 0 || k%10 > 0){
                carry += k%10;
                k /= 10;
            }

            ans.push_back(carry%10);
            carry /= 10;
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};