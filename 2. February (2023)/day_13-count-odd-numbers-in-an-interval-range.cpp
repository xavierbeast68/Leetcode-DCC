//* https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/description/
//* https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/submissions/897021661/

class Solution {
public:
    int countOdds(int low, int high) {
        // Brute force -> O(n/2) ~ O(n)
        // int count = 0;
        // int i = (low % 2) ? low : low + 1;
        // while(i <= high){
        //     count++;
        //     i += 2;
        // }
        // return count;

        // brute force optimised-> O(n/4) ~ O(n)
        // int count = 0;
        // int i = (low % 2) ? low : low + 1;
        // int j = (high % 2) ? high : high - 1;
        // while(i <= j){
        //     if(i != j){
        //         count += 2;
        //     } else {
        //         count++;
        //     }
        //     i += 2;
        //     j -= 2;
        // }
        // return count;


        // Optimised-> O(1)
        /*  diff = HIGH - LOW
            LOW     HIGH    COUNT
            odd     odd     diff + 1
            odd     even    diff + 1
            even    odd     diff + 1
            even    even    diff
        */
        if(low%2 == 0 && high%2 == 0){
            return (high-low)/2;
        } else{
            return (high-low)/2 + 1;
        }
    }
};