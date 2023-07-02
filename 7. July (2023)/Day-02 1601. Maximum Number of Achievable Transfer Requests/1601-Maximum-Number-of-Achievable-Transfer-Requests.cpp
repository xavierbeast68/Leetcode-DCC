//* https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/
//* https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/editorial

class Solution {
public:
    int reqGranted;

    bool check(vector<int> net){
        for(auto it : net){
            if(it != 0) return false;
        }
        return true;
    }
    void dfs(int ind, vector<vector<int>>& requests, int cnt, vector<int>& net){
        if(ind == requests.size()){
            if(check(net)){
                reqGranted = max(reqGranted, cnt);
            }
            return;
        }

        // take
        net[requests[ind][0]] += -1;
        net[requests[ind][1]] += 1;
        dfs(ind+1, requests, cnt+1, net);
        // backtrack
        net[requests[ind][0]] += 1;
        net[requests[ind][1]] += -1;

        // don't take
        dfs(ind+1, requests, cnt, net);
    }
    int maximumRequests(int n, vector<vector<int>>& requests) {
        reqGranted = 0;
        vector<int> net(n, 0);
        int cnt = 0;
        
        dfs(0, requests, cnt, net);

        return reqGranted;
    }
};