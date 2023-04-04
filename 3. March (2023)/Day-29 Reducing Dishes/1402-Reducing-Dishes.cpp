//* https://leetcode.com/problems/reducing-dishes/description/
//* https://leetcode.com/problems/reducing-dishes/editorial/
//* https://www.youtube.com/watch?v=_iGlRDLPLxM&ab_channel=CodeHelp-byBabbar
//* https://www.youtube.com/watch?v=jhfqrJyT3SI&ab_channel=CodeFreaks
//* https://leetcode.ca/2019-10-02-1402-Reducing-Dishes/

class Solution {
public:
    int helper(vector< int> &nums, int i, int j, vector<vector<int>> &dp){

        if(i==nums.size()){
            return 0;
        }
        if(dp[i][j]!=-1) 
            return dp[i][j];
        int pick = j*nums[i] + helper(nums, i+1, j+1, dp);
        int notpick = helper(nums,i+1,j,dp);
        return dp[i][j] = max(pick,notpick);
    }

    int maxSatisfaction(vector<int>& sat) {

        int n = sat.size();
        sort(sat.begin(),sat.end());
        vector<vector<int>>dp(n+1, vector<int>(n+1, -1));
        return helper(sat,0,1,dp);
    }
};