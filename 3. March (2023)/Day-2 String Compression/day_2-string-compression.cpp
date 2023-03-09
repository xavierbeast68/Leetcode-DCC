//* https://leetcode.com/problems/string-compression/
//* https://leetcode.ca/2017-02-15-443-String-Compression/
//* https://www.youtube.com/watch?v=-1jhUCSVvbY

class Solution {
public:
    int compress(vector<char>& chars) {
        int n = chars.size();
        if(n == 1){
            return 1;
        }
        int count = 1;
        string ans = "";
        for(int i =  0; i <= n - 2; ++i){
            if(i == n-2){
                if(chars[i] == chars[i+1]){
                    count++ ;
                    ans += chars[i] + to_string(count);
                }
                else{
                    if(count == 1){cout<<ans<<endl;
                        ans = ans + chars[i] + chars[i+1];
                        break;
                    }
                    else{
                        ans = ans + chars[i] + to_string(count) + chars[i+1];
                        break;
                    }
                }
            }

            else if(chars[i] == chars[i+1]){
                count++;
            }
            else{
                if(count == 1){
                    ans = ans + chars[i];
                }
                else{
                    ans = ans + chars[i] + to_string(count);
                    count = 1;
                }
            }
        }
        
        chars.clear();
        for(char ch : ans){
            chars.push_back(ch);
        }

        return ans.length();
    }
};