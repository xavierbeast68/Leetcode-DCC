//* https://leetcode.com/problems/koko-eating-bananas/description/
//* https://www.youtube.com/watch?v=U2SozAs9RzA
//* https://www.youtube.com/watch?v=g8AS-1vRsa4
//* https://www.geeksforgeeks.org/koko-eating-bananas/

class Solution {
public:
    bool check(vector<int>& piles, int mid, int h){
        int hours = 0;

        for(int  i : piles){
            hours += ((i%mid == 0) ? i/mid : i/mid +1);
        }

        if(hours <= h){
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(begin(piles), end(piles));

        while(l < r){
            int mid = l + (r-l)/2;

            // mid if much faster
            if(check(piles, mid, h)){
                r = mid;
            }
            else{
                l = mid + 1;
            }
        }
        return r;
    }
};