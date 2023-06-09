class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        
        //* Brute Force-> Tc- O(n)
        // char ans = 123; // 123 is ascii of character just greater than 'z'
        // for(char ch : letters){
        //     if(ch > target && ch < ans){
        //         ans = ch;
        //     }
        // }
        // return ans == 123 ? letters[0] : ans;


        //* Optimized -> Binary Search- O(logn)
        char ans = 123;
        int n = letters.size();
        int low = 0, high = n -1;

        while(low <= high){
            int mid = low + (high-low)/2;

            if(letters[mid] > target && letters[mid] < ans){
                ans = letters[mid];
            }

            if(letters[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans == 123 ? letters[0] : ans;
    }
};