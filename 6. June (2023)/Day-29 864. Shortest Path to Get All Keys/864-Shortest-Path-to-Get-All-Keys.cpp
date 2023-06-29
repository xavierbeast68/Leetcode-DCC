// https://leetcode.com/problems/shortest-path-to-get-all-keys/editorial/

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<vector<int>> q; // {row, col, key-state, distance}
        int dr[] = {-1, 0, 1, 0};
        int dc[] = {0, 1, 0, -1};

        // vis['keys'] only for BFS with key state equals 'keys'
        // entering a (row, col) with particular key-state
        map<int, set<pair<int,int>>> vis; // {key-state, {row, col}}

        int allKeys = 0; // bit mask
        int startR = -1, startC = -1;

        for(int i = 0; i < m; i++){
            for(int j = 0; j< n; j++){
                char cell = grid[i][j];

                if(cell == '@'){
                    startR = i;
                    startC = j;
                }

                else if (cell >= 'a' && cell <= 'f') {
                    allKeys += (1 << (cell - 'a'));
                }
            }
        }

        q.push({startR, startC, 0, 0});
        pair<int,int> p = {startR, startC};
        vis[0].insert(p);

        while(!q.empty()){
            vector<int> curr = q.front(); q.pop();
            int row = curr[0], col = curr[1], keys = curr[2], dist = curr[3];

            for(int i = 0; i < 4; i++){
                int newR = row + dr[i], newC = col + dc[i];

                // If this cell (newR, newC) is reachable.
                if(newR >= 0 && newR < m && newC >= 0 && newC < n && 
                    grid[newR][newC] != '#'){
                    
                    char cell = grid[newR][newC];

                    // If it is a key
                    if(grid[newR][newC] >= 'a' && grid[newR][newC] <= 'f'){

                        

                        // If we have collected it before, no need to revisit this cell.
                        if(keys & (1 << (cell-'a'))){
                            continue;
                        }

                        // Otherwise, we can walk to this cell and pick it up.
                        int newKeys = (keys | (1 << (cell-'a')));

                        // If we collect all keys, return dist + 1. 
                        // Otherwise, just add this state to seen and queue.
                        if(newKeys == allKeys){
                            return dist + 1;
                        }

                        pair<int,int> p = {newR, newC};
                        vis[newKeys].insert(p);
                        q.push({newR, newC, newKeys, dist + 1});
                    }

                    // If it is a lock and we don't have its key, continue.
                    // else we have the key to this lock(covered in else if case next)
                    if((grid[newR][newC] >= 'A' && grid[newR][newC] <= 'F') 
                        && (keys & (1 << (cell-'A'))) == 0){

                        continue;
                    }

                    // We can walk to this cell if we haven't been here before with the same key state.
                    else if(vis[keys].find(make_pair(newR, newC)) == vis[keys].end()){
                        vis[keys].insert({newR, newC});
                        q.push({newR, newC, keys, dist + 1});
                    }
                }
            }
        }

        return -1;
    }
};