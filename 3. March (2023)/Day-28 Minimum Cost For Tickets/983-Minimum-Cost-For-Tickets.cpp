//* https://leetcode.com/problems/minimum-cost-for-tickets/
//* https://leetcode.com/problems/minimum-cost-for-tickets/editorial/
//* https://www.youtube.com/watch?v=A-N1SXEOXr4&ab_channel=CodeFreaks
//* https://www.youtube.com/watch?v=4pY1bsBpIY4&ab_channel=NeetCode
//* https://www.youtube.com/watch?v=oZ_xAIGCXw4&ab_channel=CodeHelp-byBabbar
//* https://www.youtube.com/watch?v=U5f__4we_Jc&ab_channel=CodeHelp-byBabbar

class Solution {
public:

    int mincostTickets(vector<int>& days, vector<int>& costs){

        int ans = 0;

        queue<pair<int,int>> weekly;
        queue<pair<int,int>> monthly;

        for(int day : days){

            while(!monthly.empty() && (monthly.front().first + 30) <= day){
                monthly.pop();
            }
            while(!weekly.empty() && (weekly.front().first + 7) <= day){
                weekly.pop();
            }

            weekly.push(make_pair(day, ans + costs[1]));
            monthly.push(make_pair(day, ans + costs[2]));

            ans = min(ans + costs[0], min(weekly.front().second, monthly.front().second));
        }

        return ans;
    }
};