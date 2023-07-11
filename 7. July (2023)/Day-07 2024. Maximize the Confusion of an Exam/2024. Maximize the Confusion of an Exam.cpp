//* https://leetcode.com/problems/maximize-the-confusion-of-an-exam/description/
//* https://leetcode.com/problems/maximize-the-confusion-of-an-exam/editorial

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        
        Method obj;
        //* Method-1 : Binary Search + Sliding Window(fixed length)
        //  TC-> O(n.logn)
        // return obj.approach_1(answerKey, k);

        //* Method-2 : Sliding Window(variable length)
        // TC-> O(n)
        // return obj.approach_2(answerKey, k);

        //* Method-3 : Advanced Sliding Window(variable length)
        // TC-> O(n)
        return obj.approach_3(answerKey, k);
    }

    class Method{
    public:
        //* Approach-1
        int approach_1(string answerKey, int k){
            int n = answerKey.size();
            int left = k, right = n;

            while(left < right){
                int mid = right - (right - left)/2;

                if(isValid(answerKey, k, mid)){
                    left = mid;
                }
                else{
                    right = mid - 1;
                }
            }

            return left;
        }
        bool isValid(string answerKey, int k, int size){
            int n = answerKey.size();
            unordered_map<char, int> counter;

            for(int i = 0; i < size; i++){
                counter[answerKey[i]]++;
            }

            if(min(counter['T'], counter['F']) <= k){
                return true;
            }

            for(int i = size; i < n; i++){
                counter[answerKey[i]]++;
                counter[answerKey[i-size]]--;

                if(min(counter['T'], counter['F']) <= k){
                    return true;
                }
            }

            return false;
        }

        //* Approach-2
        int approach_2(string answerKey, int k){
            int ans = 1;
            int n = answerKey.length();
            map<char, int> counter;

            int i = 0,  j = 0;
            while(j < n){
                counter[answerKey[j]]++;

                while(i < j && min(counter['T'], counter['F']) > k){
                    counter[answerKey[i]]--;
                    i++;
                }

                if(min(counter['T'], counter['F']) <= k){
                    ans = max(ans, j-i+1);
                }

                j++;
            }

            return ans;
        }

        //* Approach-3
        int approach_3(string answerKey, int k){
            int ans = 1;
            int n = answerKey.length();
            map<char, int> counter;
            counter['T'] = 0, counter['F'] = 0;

            int i = 0, j = 0;
            while(j < n){
                counter[answerKey[j]]++;

                if(min(counter['T'], counter['F']) <= k){
                    ans = max(ans, j-i+1);
                }
                else{
                    counter[answerKey[i]]--;
                    i++;
                }

                j++;
            }

            return ans;
        }
    };
};