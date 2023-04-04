//* https://leetcode.com/problems/minimum-path-sum/description/
//* https://www.youtube.com/watch?v=_rgTlyky1uQ&ab_channel=takeUforward
//* https://www.youtube.com/watch?v=pGMsrvt0fpk&ab_channel=NeetCode
//* https://www.youtube.com/watch?v=S99RAK_R9rQ&ab_channel=CodeFreaks
//* https://www.codingninjas.com/codestudio/problems/minimum-path-sum_985349

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0]=grid[0][0];
        for (int i=1; i<m; i++){
                dp[i][0]=dp[i-1][0]+grid[i][0];
        }

        for (int i=1; i<n; i++){
                dp[0][i]=dp[0][i-1]+grid[0][i];
        }
        
        for (int i=1; i<m; i++){
                for (int j=1; j<n; j++){
                        dp[i][j]=min(dp[i-1][j], dp[i][j-1])+grid[i][j];
                }
        }
        return dp[m-1][n-1];
    }
};