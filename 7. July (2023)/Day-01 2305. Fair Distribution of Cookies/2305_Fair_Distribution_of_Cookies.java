//* https://leetcode.com/problems/fair-distribution-of-cookies/
//* https://leetcode.com/problems/fair-distribution-of-cookies/editorial/


class Solution {
    int min_unfair, diff;
    public void dfs(int ind, int[] cookies, int zero_count, int[] distribute, int k){
        if(ind == cookies.length && zero_count == 0){
            int maxi = Integer.MIN_VALUE;
            for(int it : distribute){
                maxi = Math.max(maxi, it);
            }
            min_unfair = Math.min(min_unfair, maxi);
            return;
        }

        int remaining = cookies.length - ind - 1;
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
    public int distributeCookies(int[] cookies, int k) {
        int[] distribute = new int[k];
        int zero_count = k;
        min_unfair = Integer.MAX_VALUE;
        diff = Integer.MAX_VALUE;

        dfs(0, cookies, zero_count, distribute, k);
        
        return min_unfair;
    }
}