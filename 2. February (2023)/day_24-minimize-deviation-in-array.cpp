//* https://leetcode.com/problems/minimize-deviation-in-array/description/
//* https://www.youtube.com/watch?v=CP7M1JrBoc8
//* https://www.youtube.com/watch?v=boHNFptxo2A
//* https://leetcode.ca/2020-07-01-1675-Minimize-Deviation-in-Array/


class Solution {
public:
    int minimumDeviation(vector<int>& nums) {

        priority_queue<int> pq;
        int m = INT_MAX;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                pq.push(nums[i]);
                m = min(m,nums[i]);
            }
            else{
                pq.push(nums[i]*2);
                m = min(m,nums[i]*2);
            }
        }
        int ans = INT_MAX;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ans = min(ans,top-m);
            if(top%2!=0){
                break;
            }
            m = min(m,top/2);
            pq.push(top/2);
        }
        return ans;
    }
};