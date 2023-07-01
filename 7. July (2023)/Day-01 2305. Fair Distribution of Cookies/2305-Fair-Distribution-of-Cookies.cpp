//* https://leetcode.com/problems/fair-distribution-of-cookies/
//* https://leetcode.com/problems/fair-distribution-of-cookies/editorial/

class Solution {
public:
    int min_unfair, diff;
    void dfs(int ind, vector<int>& cookies, int zero_count, vector<int>& distribute, int k){
        if(ind == cookies.size() && zero_count == 0){
            int maxi = INT_MIN;
            for(auto it : distribute){
                maxi = max(maxi, it);
            }
            min_unfair = min(min_unfair, maxi);
            return;
        }

        int remaining = cookies.size() - ind - 1;
        // giving indth cookie bag to a children from 0 to k-1
        for(int i = 0; i < k; i++){
            // giving another bag to a already having child
            if(distribute[i] != 0){
                if(zero_count > remaining){
                    continue;
                }
                else{
                    distribute[i] += cookies[ind];
                    dfs(ind+1, cookies, zero_count, distribute, k);
                    distribute[i] -= cookies[ind];
                }
            }
            // giving cookie bag to a child for first time
            else{
                distribute[i] += cookies[ind];
                dfs(ind+1, cookies, zero_count - 1, distribute, k);
                distribute[i] -= cookies[ind];
            }
        }
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> distribute(k, 0);
        int zero_count = k;
        min_unfair = INT_MAX;
        diff = INT_MAX;
        dfs(0, cookies, zero_count, distribute, k);
        
        return min_unfair;
    }
};