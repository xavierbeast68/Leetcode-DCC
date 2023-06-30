//* https://leetcode.com/problems/last-day-where-you-can-still-cross/
//* https://leetcode.com/problems/last-day-where-you-can-still-cross/editorial/
//* https://www.youtube.com/watch?v=rKpDqeL8knY&ab_channel=CodeFreaks


class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        // Method-1: Using BFS + Binary Search
        // TC-> O(row⋅col⋅log(row⋅col))
        // Method_1_2 obj;
        // return obj.lastDay(row, col, cells);

        // Method-2: Using DFS + Binary Search
        // TC-> O(row⋅col⋅log(row⋅col))
        // Method_1_2 obj;
        // return obj.lastDay(row, col, cells);


        // Method-3: Disjoint Set Union (on water cells)
        // O(row⋅col⋅α(row⋅col))
        // Method_3_4 obj;
        // return obj.lastDay(row, col, cells);

        // Method-4: Disjoint Set Union (on land cells)
        // O(row⋅col)
        Method_3_4 obj;
        return obj.lastDay(row, col, cells);
    }

    class Method_1_2{
    public:
        // Using Binary Search + BFS
        bool canCrossBFS(int row, int col, vector<vector<int>>& cells, int day){
            vector<vector<int>> grid(row, vector<int>(col, 0));
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};

            // {row, col}
            queue<pair<int, int>> q;

            // current state of grid at day = day
            for(int i = 0; i < day; i++){
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }
            
            // Applying BFS
            // adding source points
            for(int i = 0; i < col; i++){
                if(grid[0][i] == 0){
                    q.push({0, i});
                    grid[0][i] = -1; // marking as visited
                }
            }
            while(!q.empty()){
                // pair<int,int> curr = q.front();
                // q.pop();
                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                // if reached the bottom row
                if(r == row-1){
                    return true;
                }

                for(int i = 0; i < 4; i++){
                    int newR = r + dr[i], newC = c + dc[i];

                    if(newR < row && newR >= 0 && newC < col && newC >= 0
                        && grid[newR][newC] == 0){
                            
                        q.push({newR, newC});
                        grid[newR][newC] = -1;
                    }
                }
            }
            
            return false;
        }

        // Using Binary Search + DFS
        bool dfs(int r, int c, int row, int col, vector<vector<int>>& grid, int dr[], int dc[]){
            grid[r][c] = -1;

            // reached last row
            if (r == row - 1) {
                return true;
            }

            for(int i = 0; i < 4; i++){
                int newR = r + dr[i], newC = c + dc[i];

                if(newR < row && newR >= 0 && newC < col && newC >= 0
                    && grid[newR][newC] == 0){

                    if(dfs(newR, newC, row, col, grid, dr, dc) == true){
                        return true;
                    }
                }
            }
            return false;
        }
        bool canCrossDFS(int row, int col, vector<vector<int>>& cells, int day){
            vector<vector<int>> grid(row, vector<int>(col, 0));
            int dr[] = {-1, 0, 1, 0};
            int dc[] = {0, 1, 0, -1};
            // current state of grid at day = day
            for(int i = 0; i < day; i++){
                grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
            }

            // Applying DFS
            for(int i = 0; i < col; i++){
                if(grid[0][i] == 0 && dfs(0, i, row, col, grid, dr, dc) == true){
                    return true;
                }
            }

            return false;
        }

        int lastDay(int row, int col, vector<vector<int>>& cells){
            // Binary Search->
            int left = 1, right = row*col; // in worst case, maximum days/queries can be row*col

            while(left < right){
                int mid = right - (right - left)/2;

                // if(canCrossBFS(row, col, cells, mid)){
                //     left = mid;
                // }
                if(canCrossDFS(row, col, cells,mid)){
                    left = mid;
                }
                else{
                    right = mid - 1;
                }
            }

            return left;
        }
    };


    class Method_3_4{
    public:
        int onWater(int row, int col, vector<vector<int>>& cells){
            DisjointSet dsu(row * col + 2);

            vector<vector<int>> grid(row, vector<int> (col, 0));
            int directions[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, 
                                    {1, -1}, {-1, 1}, {-1, -1}};

            // replacing water cells with land cells and adding them in dsu->
            for(int i = 0; i < cells.size(); i++){
                int r = cells[i][0] - 1, c = cells[i][1] - 1;
                grid[r][c] = 1;

                int index1 = r * col + c + 1;

                // checking for water cell in all 8 directions
                for(auto dir : directions){
                    int newR = r + dir[0], newC = c + dir[1];
                    int index2 = newR * col + newC + 1;

                    if (newR >= 0 && newR < row && newC >= 0 && newC < col 
                        && grid[newR][newC] == 1){

                        dsu.unionBySize(index1, index2);
                    }
                }

                if(c == 0){
                    dsu.unionBySize(0, index1);
                }
                if(c == col-1){
                    dsu.unionBySize(row * col + 1, index1);
                }
                if(dsu.findUPar(0) == dsu.findUPar(row*col+1)){
                    return i;
                }
            }

            return -1;
        }

        int onLand(int row, int col, vector<vector<int>>& cells){
            DisjointSet dsu(row * col + 2);
            int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            vector<vector<int>> grid(row, vector<int> (col, 0));

            for(int i = 0; i < cells.size(); i++){
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }

            for(int i = 0; i < row; i++){
                for(int j = 0; j < col; j++){
                    int index1 = i * col + j + 1;
                    if(grid[i][j] == 0){
                        for(auto dir : directions){
                            int newR = i + dir[0], newC = j + dir[1];
                            int index2 = newR * col + newC + 1;

                            if (newR >= 0 && newR < row && newC >= 0 && newC < col 
                                && grid[newR][newC] == 0){
                                
                                dsu.unionBySize(index1, index2);
                            }
                        }

                        if(i == 0){
                            dsu.unionBySize(0, index1);
                        }
                        if(i == row-1){
                            dsu.unionBySize(row * col + 1, index1);
                        }
                    }
                }
            }
            if(dsu.findUPar(0) == dsu.findUPar(row*col+1)){
                return cells.size();
            }


            for(int i = cells.size()-1; i >= 0; i--){
                int r = cells[i][0]-1, c = cells[i][1] - 1;
                grid[r][c] = 0;
                int index1 = r * col + c + 1;
                
                for (auto d : directions) {
                    int newR = r + d[0], newC = c + d[1];
                    int index2 = newR * col + newC + 1;
                    if (newR >= 0 && newR < row && newC >= 0 && newC < col 
                        && grid[newR][newC] == 0) {
                            dsu.unionBySize(index1, index2);
                        }
                }
                if (r == 0) {
                    dsu.unionBySize(0, index1);
                }
                if (r == row - 1) {
                    dsu.unionBySize(row * col + 1, index1);
                }
                if (dsu.findUPar(0) == dsu.findUPar(row * col + 1)) {
                    return i;
                }
            }
            return -1;
        }

        int lastDay(int row, int col, vector<vector<int>>& cells){
            // Disjoint Set Union (on water cells)
            // return onWater(row, col, cells);
            
            // Disjoint Set Union (on land cells)
            return onLand(row, col, cells);
        }
    };


    //* <------------------------- Disjoint Set Util Starts ------------------------->

    class DisjointSet{
    public:
        vector<int> parent, rank, size;

        // constructor
        DisjointSet(int n){
            parent.resize(n + 1);
            rank.resize(n + 1, 0);
            size.resize(n + 1);

            for(int i = 0; i <= n; ++i){
                parent[i] = i;
                size[i] = 1;
            }
        }

        // find ultimate parent
        int findUPar(int node){
            if(parent[node] == node){
                return node;
            }

            return parent[node] = findUPar(parent[node]); // does path compression as well
        }

        // union by rank
        void unionByRank(int u, int v){
            int ulp_u = findUPar(u); // calculate ultimate parent of u
            int ulp_v = findUPar(v); // calculate ultimate parent of v

            // if both have same ULP, means both are in same set
            if(ulp_u == ulp_v){
                return;
            }

            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }
        }

        // union by size
        void unionBySize(int u, int v){
            int ulp_u = findUPar(u); // calculate ultimate parent of u
            int ulp_v = findUPar(v); // calculate ultimate parent of v

            // if both have same ULP, means both are in same set
            if(ulp_u == ulp_v){
                return;
            }

            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
    };

    //* <------------------------- Disjoint Set Util Ends ------------------------->
};