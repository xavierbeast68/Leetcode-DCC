//* https://leetcode.com/problems/jump-game-iv/description/
//* https://www.youtube.com/watch?v=JYbU8RH1OSQ
//* https://leetcode.ca/2019-08-06-1345-Jump-Game-IV/

class Solution {
public:
    int minJumps(vector<int>& arr) {

        if(arr.size() == 1){
            return 0;
        }

        unordered_map<int, vector<int>> mp;
        int n = arr.size(), step = 0;
        for(int i = 0 ; i < n ; ++i){
            mp[arr[i]].push_back(i);
        }

        vector<bool> seen(n);
        seen[0] = true;
        queue<int> q{{0}};

        while(q.size()){
            int cnt = q.size();
            
            while(cnt--){
                int i = q.front();
                q.pop();

                if(i == n-1){
                    return step;
                }

                // checking for i-1
                if(i-1 > 0 && !seen[i-1]){
                    q.push(i-1);
                    seen[i-1] = true;
                }
                // checking for i+1
                if(i+1 < n && !seen[i+1]){
                    q.push(i+1);
                    seen[i+1] = true;
                }
                // checking for arr[i]==arr[j] where i!=j
                if(mp.count(arr[i])){
                    for(int j : mp[arr[i]]){
                        // if already visited that index j
                        if(seen[j]){
                            continue;
                        }

                        // if not yet visited
                        seen[j] = true;
                        q.push(j);
                    }

                    mp.erase(arr[i]);
                }
            }
            // one step completed
            ++step;
        }
        return -1;
    }
};