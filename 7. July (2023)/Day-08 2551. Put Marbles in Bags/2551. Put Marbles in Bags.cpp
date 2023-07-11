//* https://leetcode.com/problems/put-marbles-in-bags
//* https://leetcode.com/problems/put-marbles-in-bags/editorial/
// typical stick and stones problem : https://www.youtube.com/watch?v=bE-1JN4zm5A
//* https://youtu.be/czT67Xo_Sis
//* 

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();

        long long mini, maxi;
        mini = maxi = weights[0] + weights[n-1];

        if(n == 1 || n == 2){
            return maxi - mini;
        }

        vector<int> pairSum;
        for(int i = 0; i < n-1; i++){
            pairSum.push_back(weights[i] + weights[i+1]);
        }

        sort(pairSum.begin(), pairSum.end());
        int nn = pairSum.size();
        
        // for(int i = 0; i < k-1; ++i){
        //     mini = mini + pairSum[i];
        //     maxi = maxi + pairSum[nn-i-1];
        // }

        maxi = maxi + accumulate(pairSum.begin() + (nn-(k-1)), pairSum.end(), 0ll);
        mini = mini + accumulate(pairSum.begin(), pairSum.begin() + (k-1), 0ll);

        return maxi - mini;
    }
};