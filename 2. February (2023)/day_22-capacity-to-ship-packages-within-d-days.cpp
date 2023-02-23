//* https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/description/
//* https://www.youtube.com/watch?v=ER_oLmdc-nw

class Solution {
public:
    bool canShip(int cap, vector<int>& wt, int days){
        int ships = 1, currCap = cap;
        for(auto w : wt){
            if((currCap - w) < 0){
                ships++;
                currCap = cap;
            }
            currCap -= w;
        }
        return (ships <= days);
    }
    int helper(int lb, int ub, vector<int>& wt, int days){
        int res = ub, cap = (lb+ub)/2;;
        while(lb <= ub){
            cap = (lb+ub)/2;
            if(canShip(cap, wt,days)){
                res = min(res,cap);
                ub = cap - 1;
            }
            else{
                lb = cap + 1;
            }
        }
        return res;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int lower_bound = *max_element(weights.begin(), weights.end());
        int upper_bound = accumulate(weights.begin(), weights.end(), 0);

        int answer = helper(lower_bound, upper_bound, weights, days);
        return answer;
    }
};