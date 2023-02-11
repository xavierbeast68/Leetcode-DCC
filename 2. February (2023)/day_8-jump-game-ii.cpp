//* https://leetcode.com/problems/jump-game-ii/
//* https://leetcode.com/problems/jump-game-ii/submissions/893836200/
//* https://www.youtube.com/watch?v=dJ7sWiOoK7g
//* https://leetcode.com/problems/jump-game-ii/solutions/3076867/jump-game-ii/


// class Solution {
// public:
//     int number_of_moves(vector<int>& nums, int moves, int i, int n){
//         if(i == n-1){
//             return moves;
//         }
        
//         // when jump taken
//         else if(i + nums[i] <= n-1){
//             int move1 = number_of_moves(nums, moves + 1, i + nums[i], n);
//             int move2 = number_of_moves(nums, moves + 1, i + 1, n);
//             return min(move1, move2);
//         }
//         else{
//             // when jump not taken
//             int move2 = number_of_moves(nums, moves + 1, i + 1, n);
//             return move2;
//         }
//     }
//     int jump(vector<int>& nums) {
//         int n = nums.size();
//         int moves = number_of_moves(nums, 0, 0, n);
//         return moves;
//     }
// };

class Solution {
public:
    int jump(vector<int>& nums) {
        // The starting range of the first jump is [0, 0]
        int answer = 0, n = int(nums.size());

        int curEnd = 0, curFar = 0;
        
        for (int i = 0; i < n - 1; ++i) {
            // Update the farthest reachable index of this jump.
            curFar = max(curFar, i + nums[i]);

            // If we finish the starting range of this jump,
            // Move on to the starting range of the next jump.
            if (i == curEnd) {
                answer++;
                curEnd = curFar;
            }
        }
        
        return answer;
    }
};