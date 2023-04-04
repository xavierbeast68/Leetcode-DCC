//* https://leetcode.com/problems/boats-to-save-people/description/
//* https://leetcode.com/problems/boats-to-save-people/editorial/
//* https://www.youtube.com/watch?v=XbaxWuHIWUs&ab_channel=NeetCode

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int n = people.size();
        int cnt = 0;
        int low = 0, high = n-1;
        while(low <= high){
            if(people[low] + people[high] <= limit || low == high){
                low++;
                high--;
                cnt++;
            }
            else{
                high--;
                cnt++;
            }
        }

        return cnt;
    }
};