// https://leetcode.com/problems/min-cost-climbing-stairs/description/

class Solution {
public:
    int rec(int i, vector<int> cost, vector<int>& dp){
        if(i < 0){
            return 0;
        }

        if(dp[i] != -1){
            return dp[i];
        }

        int OneStep = cost[i] + rec(i-1, cost, dp);
        int TwoStep = cost[i] + rec(i-2, cost, dp);

        return dp[i] = min(OneStep, TwoStep);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        cost.push_back(0);
        int n = cost.size();
        vector<int> dp(n, -1);
        dp[0] = cost[0];
        dp[1] = cost[1];

        rec(n-1, cost, dp);

        return dp[n-1];
    }
};